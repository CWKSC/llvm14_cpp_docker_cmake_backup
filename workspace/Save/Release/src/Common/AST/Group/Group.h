#pragma once

#include <iostream>
#include <list>
#include <vector>

#include "../../Token/TaggedToken/TaggedToken.h"

#include "../Node/Node.h"

#include "llvm/IR/Value.h"

namespace AST {

struct Group : Node {
  std::vector<Node *> nodeList;

  Group(Parser *parser, Group *parent) : Node(parser, parent) {}
  ~Group();

  static Group *parsing(Parser *parser, Group *parent,
                        std::list<TaggedToken> &taggedTokenList);
  static std::list<Node *>
  parsingInside(Parser *parser, Group *parent,
                std::list<TaggedToken> &taggedTokenList);
  llvm::Value *codegen(CodeGenerator *codeGenerator);
  void print(std::ostream &os, int indent = 0) const;
  void printInside(std::ostream &os, int indent = 0) const;
};

} // namespace AST