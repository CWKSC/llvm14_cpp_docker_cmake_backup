
#include <iostream>
#include <list>
#include <string>

#include "../../../CodeGenerator/CodeGenerator.h"
#include "../../../Parser/Parser.h"

#include "../../Parsing/parsing.h"
#include "../../Token/TaggedToken/TaggedToken.h"

#include "../Group/Group.h"

#include "If.h"

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

If::~If() {}

If *If::parsing(Parser *parser, Group *parent,
                std::list<TaggedToken> &taggedTokenList) {
  Parsing::exceptASTNode(taggedTokenList, "if");
  If *if_ = new If(parser, parent);
  auto condition = Node::parsing(parser, parent, taggedTokenList);
  auto then = Group::parsing(parser, parent, taggedTokenList);
  Group *else_ = nullptr;
  if (taggedTokenList.front().tag == "else") {
    taggedTokenList.pop_front();
    else_ = Group::parsing(parser, parent, taggedTokenList);
  }
  if_->condition = condition;
  if_->then = then;
  if_->else_ = else_;
  return if_;
}

llvm::Value *If::codegen(CodeGenerator *codeGenerator) {
  llvm::Value *CondV = condition->codegen(codeGenerator);
  if (!CondV)
    return nullptr;

  // Convert condition to a bool by comparing non-equal to 0.0.
  CondV = codeGenerator->Builder->CreateFCmpONE(
      CondV, ConstantFP::get(*codeGenerator->TheContext, APFloat(0.0)),
      "ifcond");

  Function *TheFunction = codeGenerator->Builder->GetInsertBlock()->getParent();

  // Create blocks for the then and else cases.  Insert the 'then' block at the
  // end of the function.
  BasicBlock *ThenBB =
      BasicBlock::Create(*codeGenerator->TheContext, "then", TheFunction);
  BasicBlock *ElseBB = BasicBlock::Create(*codeGenerator->TheContext, "else");
  BasicBlock *MergeBB =
      BasicBlock::Create(*codeGenerator->TheContext, "ifcont");

  codeGenerator->Builder->CreateCondBr(CondV, ThenBB, ElseBB);

  // Emit then value.
  codeGenerator->Builder->SetInsertPoint(ThenBB);

  Value *ThenV = then->codegen(codeGenerator);
  if (!ThenV)
    return nullptr;

  codeGenerator->Builder->CreateBr(MergeBB);
  // Codegen of 'Then' can change the current block, update ThenBB for the PHI.
  ThenBB = codeGenerator->Builder->GetInsertBlock();

  // Emit else block.
  TheFunction->getBasicBlockList().push_back(ElseBB);
  codeGenerator->Builder->SetInsertPoint(ElseBB);

  Value *ElseV = else_->codegen(codeGenerator);
  if (!ElseV)
    return nullptr;

  codeGenerator->Builder->CreateBr(MergeBB);
  // Codegen of 'Else' can change the current block, update ElseBB for the PHI.
  ElseBB = codeGenerator->Builder->GetInsertBlock();

  // Emit merge block.
  TheFunction->getBasicBlockList().push_back(MergeBB);
  codeGenerator->Builder->SetInsertPoint(MergeBB);
  PHINode *PN = codeGenerator->Builder->CreatePHI(
      Type::getDoubleTy(*codeGenerator->TheContext), 2, "iftmp");

  PN->addIncoming(ThenV, ThenBB);
  PN->addIncoming(ElseV, ElseBB);
  return PN;
}

void If::print(std::ostream &os, int indent) const {
  os << "if (" << std::endl;
  indent += 4;

  os << std::string(indent, ' ');
  os << "condition: ";
  condition->print(os, indent);
  os << std::endl;

  os << std::string(indent, ' ');
  os << "then: ";
  then->print(os, indent);
  os << std::endl;

  if (else_ != nullptr) {
    os << std::string(indent, ' ');
    os << "else: ";
    else_->print(os, indent);
    os << std::endl;
  }

  indent -= 4;
  os << std::string(indent, ' ') << ")";
}
