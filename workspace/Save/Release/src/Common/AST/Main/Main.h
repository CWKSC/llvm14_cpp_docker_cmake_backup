#pragma once

#include <iostream>
#include <list>

#include "../../Token/TaggedToken/TaggedToken.h"

#include "../../Parsing/parsing.h"

#include "../Func/Func.h"

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

struct Main : Node {
  Func *func;

  Main(Parser *parser, Group *parent) : Node(parser, parent) {}
  ~Main();

  static Node *parsing(Parser *parser, Group *parent,
                       std::list<TaggedToken> &taggedTokenList);
  llvm::Value *codegen(CodeGenerator *codeGenerator);
  void print(std::ostream &os, int indent = 0) const;
};

} // namespace AST
