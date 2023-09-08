
#include <iostream>
#include <list>
#include <string>

#include "../../../Parser/Parser.h"

#include "../../Parsing/parsing.h"
#include "../../Token/TaggedToken/TaggedToken.h"

#include "../Callee/Callee.h"
#include "../Group/Group.h"
#include "../Prototype/Prototype.h"

#include "Func.h"

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

Func::~Func() {}

Func *Func::parsing(Parser *parser, Group *parent,
                    std::list<TaggedToken> &taggedTokenList) {
  Parsing::exceptASTNode(taggedTokenList, "func");
  Prototype *prototype = Prototype::parsing(parser, parent, taggedTokenList);

  Parser *function_parser = new Parser(parser);
  for (auto arg : prototype->argNames) {
    function_parser->variables.insert(arg);
  }
  Group *group = Group::parsing(function_parser, parent, taggedTokenList);

  Func *func = new Func(parser, parent);
  func->prototype = prototype;
  func->body = group;
  std::cout << "Parsing a function" << std::endl;
  func->print(std::cout, 0);

  parser->prototypes[prototype->name] = prototype;
  return func;
}

llvm::Value *Func::codegen(CodeGenerator *codeGenerator) {
  // First, check for an existing function from a previous 'extern' declaration.
  llvm::Function *TheFunction =
      codeGenerator->TheModule->getFunction(prototype->name);

  if (!TheFunction)
    TheFunction = prototype->codegen(codeGenerator);

  if (!TheFunction)
    return nullptr;

  // Create a new basic block to start insertion into.
  llvm::BasicBlock *BB = llvm::BasicBlock::Create(*codeGenerator->TheContext,
                                                  "entry", TheFunction);
  codeGenerator->Builder->SetInsertPoint(BB);

  // Record the function arguments in the NamedValues map.
  codeGenerator->NamedValues.clear();
  for (auto &Arg : TheFunction->args())
    codeGenerator->NamedValues[std::string(Arg.getName())] = &Arg;

  if (llvm::Value *RetVal = body->codegen(codeGenerator)) {
    // Finish off the function.
    codeGenerator->Builder->CreateRet(RetVal);

    // Validate the generated code, checking for consistency.
    verifyFunction(*TheFunction);

    return TheFunction;
  }

  // Error reading body, remove function.
  TheFunction->eraseFromParent();
  return nullptr;
}

void Func::print(std::ostream &os, int indent) const {
  os << "func ";
  prototype->print(os, indent);
  os << " (" << std::endl;
  indent += 4;
  auto nodeList = body->nodeList;
  for (auto &node : nodeList) {
    os << std::string(indent, ' ');
    node->print(os, indent);
    os << std::endl;
  }
  indent -= 4;
  os << std::string(indent, ' ') << ")";
}
