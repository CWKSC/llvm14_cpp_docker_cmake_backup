
#include <iostream>
#include <list>
#include <string>

#include "../../../CodeGenerator/CodeGenerator.h"
#include "../../../Parser/Parser.h"

#include "../../Parsing/parsing.h"
#include "../../Token/TaggedToken/TaggedToken.h"

#include "../Group/Group.h"

#include "For.h"

#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"

using namespace AST;
using namespace llvm;

For::~For() {}

For *For::parsing(Parser *parser, Group *parent,
                  std::list<TaggedToken> &taggedTokenList) {
  Parsing::exceptASTNode(taggedTokenList, "for");
  For *for_ = new For(parser, parent);

  auto variable = Variable::parsing(parser, parent, taggedTokenList);

  auto init = Integer::parsing(parser, parent, taggedTokenList);
  auto upperLimit = Integer::parsing(parser, parent, taggedTokenList);
  auto step = Integer::parsing(parser, parent, taggedTokenList);

  Parser *forParser = new Parser(parser);
  forParser->variables.insert(variable->name);
  auto body = Group::parsing(forParser, parent, taggedTokenList);

  for_->variable = variable;
  for_->init = init;
  for_->upperLimit = upperLimit;
  for_->step = step;
  for_->body = body;
  return for_;
}

llvm::Value *For::codegen(CodeGenerator *codeGenerator) {

  // Emit the start code first, without 'variable' in scope.
  Value *StartVal = init->codegen(codeGenerator);
  if (!StartVal)
    return nullptr;

  // Make the new basic block for the loop header, inserting after current
  // block.
  Function *TheFunction = codeGenerator->Builder->GetInsertBlock()->getParent();
  BasicBlock *PreheaderBB = codeGenerator->Builder->GetInsertBlock();
  BasicBlock *LoopBB =
      BasicBlock::Create(*codeGenerator->TheContext, "loop", TheFunction);

  // Insert an explicit fall through from the current block to the LoopBB.
  codeGenerator->Builder->CreateBr(LoopBB);

  // Start insertion in LoopBB.
  codeGenerator->Builder->SetInsertPoint(LoopBB);

  LoopBB->print(errs());

  // Start the PHI node with an entry for Start.
  PHINode *Variable = codeGenerator->Builder->CreatePHI(
      Type::getDoubleTy(*codeGenerator->TheContext), 2, variable->name.c_str());
  Variable->addIncoming(StartVal, PreheaderBB);

  // Within the loop, the variable is defined equal to the PHI node.  If it
  // shadows an existing variable, we have to restore it, so save it now.
  Value *OldVal = codeGenerator->NamedValues[variable->name];
  codeGenerator->NamedValues[variable->name] = Variable;

  // Emit the body of the loop.  This, like any other expr, can change the
  // current BB.  Note that we ignore the value computed by the body, but don't
  // allow an error.
  if (!body->codegen(codeGenerator))
    return nullptr;

  // Emit the step value.
  Value *StepVal = nullptr;
  if (step) {
    StepVal = step->codegen(codeGenerator);
    if (!StepVal)
      return nullptr;
  } else {
    // If not specified, use 1.0.
    StepVal = ConstantFP::get(*codeGenerator->TheContext, APFloat(1.0));
  }

  Value *NextVar =
      codeGenerator->Builder->CreateFAdd(Variable, StepVal, "nextvar");

  // Compute the end condition.
  Value *UpperLimit = upperLimit->codegen(codeGenerator);
  if (!UpperLimit)
    return nullptr;

  std::cout << "here3" << std::endl;
  // Convert condition to a bool by comparing non-equal to 0.0.
  auto EndCond =
      codeGenerator->Builder->CreateFCmpONE(UpperLimit, Variable, "loopcond");

  // Create the "after loop" block and insert it.
  BasicBlock *LoopEndBB = codeGenerator->Builder->GetInsertBlock();
  BasicBlock *AfterBB =
      BasicBlock::Create(*codeGenerator->TheContext, "afterloop", TheFunction);

  // Insert the conditional branch into the end of LoopEndBB.
  codeGenerator->Builder->CreateCondBr(EndCond, LoopBB, AfterBB);

  // Any new code will be inserted in AfterBB.
  codeGenerator->Builder->SetInsertPoint(AfterBB);

  // Add a new entry to the PHI node for the backedge.
  Variable->addIncoming(NextVar, LoopEndBB);

  // Restore the unshadowed variable.
  if (OldVal)
    codeGenerator->NamedValues[variable->name] = OldVal;
  else
    codeGenerator->NamedValues.erase(variable->name);

  // for expr always returns 0.0.
  return Constant::getNullValue(Type::getDoubleTy(*codeGenerator->TheContext));
}

void For::print(std::ostream &os, int indent) const {
  os << "for (" << std::endl;
  indent += 4;

  os << std::string(indent, ' ');
  variable->print(os, indent);
  os << std::endl;

  os << std::string(indent, ' ') << "init: ";
  init->print(os, indent);
  os << std::endl;

  os << std::string(indent, ' ') << "upperLimit: ";
  upperLimit->print(os, indent);
  os << std::endl;

  os << std::string(indent, ' ') << "step: ";
  step->print(os, indent);
  os << std::endl;

  os << std::string(indent, ' ') << "body: ";
  body->print(os, indent);
  os << std::endl;

  indent -= 4;
  os << std::string(indent, ' ') << ")";
}
