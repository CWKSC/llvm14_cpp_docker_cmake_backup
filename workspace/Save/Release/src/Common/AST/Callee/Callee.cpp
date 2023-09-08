
#include <iostream>
#include <list>
#include <string>

#include "../../../CodeGenerator/CodeGenerator.h"
#include "../../../Parser/Parser.h"

#include "../../Parsing/parsing.h"
#include "../../Token/TaggedToken/TaggedToken.h"

#include "../Group/Group.h"

#include "Callee.h"

#include "llvm/ADT/APFloat.h"
#include "llvm/IR/Constants.h"

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

Callee::~Callee() {}

Callee *Callee::parsing(Parser *parser, Group *parent,
                        std::list<TaggedToken> &taggedTokenList) {
  Callee *callee = new Callee(parser, parent);

  callee->name = taggedTokenList.front().baseToken.string;
  taggedTokenList.pop_front();

  Prototype *prototype = parser->prototypes[callee->name];
  for (int i = 0; i < prototype->argNames.size(); i++) {
    callee->args.push_back(Node::parsing(parser, parent, taggedTokenList));
  }
  return callee;
}

llvm::Value *Callee::codegen(CodeGenerator *codeGenerator) {
  // Look up the name in the global module table.
  llvm::Function *CalleeF = codeGenerator->TheModule->getFunction(name);
  if (!CalleeF) {
    return nullptr;
  }

  // If argument mismatch error.
  if (CalleeF->arg_size() != args.size()) {
    return nullptr;
  }

  std::vector<llvm::Value *> ArgsV;
  for (unsigned i = 0, e = args.size(); i != e; ++i) {
    ArgsV.push_back(args[i]->codegen(codeGenerator));
    if (!ArgsV.back())
      return nullptr;
  }

  return codeGenerator->Builder->CreateCall(CalleeF, ArgsV, "calltmp");
}

void Callee::print(std::ostream &os, int indent) const {
  os << "Callee " << name << " (" << std::endl;
  for (auto arg : args) {
    os << std::string(indent + 4, ' ');
    arg->print(os);
    os << std::endl;
  }
  os << std::string(indent, ' ') << ")";
}
