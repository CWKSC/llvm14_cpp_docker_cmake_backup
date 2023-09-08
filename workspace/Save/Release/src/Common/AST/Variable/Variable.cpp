
#include <iostream>
#include <list>
#include <string>

#include "../../../CodeGenerator/CodeGenerator.h"
#include "../../../Parser/Parser.h"

#include "../../Parsing/parsing.h"
#include "../../Token/TaggedToken/TaggedToken.h"

#include "../Group/Group.h"

#include "Variable.h"

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

Variable::~Variable() {}

Variable *Variable::parsing(Parser *parser, Group *parent,
                            std::list<TaggedToken> &taggedTokenList) {
  Variable *variable = new Variable(parser, parent);
  variable->name = taggedTokenList.front().baseToken.string;
  taggedTokenList.pop_front();
  return variable;
}

llvm::Value *Variable::codegen(CodeGenerator *codeGenerator) {
  llvm::Value *V = codeGenerator->NamedValues[name];
  if (!V) {
    std::cout << "Unknown variable name" << std::endl;
    return nullptr;
  }
  return V;
}

void Variable::print(std::ostream &os, int indent) const {
  os << "variable - " << name;
}
