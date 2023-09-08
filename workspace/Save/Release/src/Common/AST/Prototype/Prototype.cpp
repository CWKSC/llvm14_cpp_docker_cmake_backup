
#include <iostream>
#include <list>
#include <string>

#include "../../../CodeGenerator/CodeGenerator.h"

#include "../../Parsing/parsing.h"
#include "../../Token/TaggedToken/TaggedToken.h"

#include "../Group/Group.h"

#include "Prototype.h"

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

Prototype::~Prototype() {}

Prototype *Prototype::parsing(Parser *parser, Group *parent,
                              std::list<TaggedToken> &taggedTokenList) {
  Prototype *prototype = new Prototype(parser, parent);
  prototype->name = taggedTokenList.front().baseToken.string;
  taggedTokenList.pop_front();
  Parsing::exceptASTNode(taggedTokenList, "(");
  while (!taggedTokenList.empty()) {
    auto front = taggedTokenList.front();
    taggedTokenList.pop_front();
    if (front.tag == ")") {
      break;
    }
    prototype->argNames.push_back(front.baseToken.string);
  }
  return prototype;
}

llvm::Function *Prototype::codegen(CodeGenerator *codeGenerator) {
  // Make the function type:  double(double,double) etc.
  std::vector<llvm::Type *> Doubles(
      argNames.size(), llvm::Type::getDoubleTy(*codeGenerator->TheContext));
  llvm::FunctionType *FT = llvm::FunctionType::get(
      llvm::Type::getDoubleTy(*codeGenerator->TheContext), Doubles, false);

  llvm::Function *F = llvm::Function::Create(
      FT, llvm::Function::ExternalLinkage, name, *codeGenerator->TheModule);

  // Set names for all arguments.
  unsigned Idx = 0;
  for (auto &Arg : F->args())
    Arg.setName(argNames[Idx++]);

  return F;
}

void Prototype::print(std::ostream &os, int indent) const {
  os << name << " (";
  for (auto &argName : argNames) {
    os << " " << argName;
  }
  os << " )";
}
