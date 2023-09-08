#pragma once

#include <iostream>
#include <list>
#include <vector>

#include "../../Parsing/parsing.h"
#include "../../Token/TaggedToken/TaggedToken.h"

#include "../Node/Node.h"

#include "llvm/IR/Value.h"

namespace AST {

struct Float : Node {
  float value;

  Float(Parser *parser, Group *parent) : Node(parser, parent) {}
  ~Float();

  static Float *parsing(Parser *parser, Group *parent,
                        std::list<TaggedToken> &taggedTokenList);
  llvm::Value *codegen(CodeGenerator *codeGenerator);
  void print(std::ostream &os, int indent = 0) const;
};

} // namespace AST
