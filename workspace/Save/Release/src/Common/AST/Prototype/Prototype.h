
#pragma once

#include <iostream>
#include <list>
#include <vector>

#include "../../Parsing/parsing.h"
#include "../../Token/TaggedToken/TaggedToken.h"

#include "../Node/Node.h"

#include "llvm/IR/Value.h"

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

namespace AST {

struct Prototype : Node {
  std::string name;
  std::vector<std::string> argNames;

  Prototype(Parser *parser, Group *parent) : Node(parser, parent) {}
  ~Prototype();

  static Prototype *parsing(Parser *parser, Group *parent,
                            std::list<TaggedToken> &taggedTokenList);
  llvm::Function *codegen(CodeGenerator *codeGenerator);
  void print(std::ostream &os, int indent = 0) const;
};

} // namespace AST
