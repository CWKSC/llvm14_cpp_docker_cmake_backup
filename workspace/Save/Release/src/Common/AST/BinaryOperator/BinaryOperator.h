#pragma once

#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "../../Parsing/parsing.h"
#include "../../Token/TaggedToken/TaggedToken.h"

#include "../Node/Node.h"

#include "llvm/IR/Value.h"

namespace AST {

struct BinaryOperator : Node {
  std::string operatorString;
  Node *node1;
  Node *node2;

  BinaryOperator(Parser *parser, Group *parent) : Node(parser, parent) {}
  ~BinaryOperator();

  static BinaryOperator *parsing(Parser *parser, Group *parent,
                                 std::list<TaggedToken> &taggedTokenList);
  llvm::Value *codegen(CodeGenerator *codeGenerator);
  void print(std::ostream &os, int indent = 0) const;
};

} // namespace AST
