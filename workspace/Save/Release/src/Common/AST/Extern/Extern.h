#pragma once

#include <iostream>
#include <list>
#include <vector>

#include "../../Token/TaggedToken/TaggedToken.h"

#include "../Node/Node.h"

#include "llvm/IR/Value.h"

#include "../../../CodeGenerator/CodeGenerator.h"

struct ParsingContext;

namespace AST {

struct Prototype;

struct Extern : AST::Node {
  Prototype *prototype;

  Extern(Parser *parser, Group *parent) : Node(parser, parent) {}
  ~Extern();

  static Extern *parsing(Parser *parser, Group *parent,
                         std::list<TaggedToken> &taggedTokenList);
  llvm::Value *codegen(CodeGenerator *codeGenerator);
  void print(std::ostream &os, int indent = 0) const;
};

} // namespace AST
