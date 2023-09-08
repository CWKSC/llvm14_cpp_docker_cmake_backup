#pragma once

#include <iostream>
#include <list>
#include <vector>

#include "../../Token/TaggedToken/TaggedToken.h"

#include "llvm/IR/Value.h"

struct Parser;
struct CodeGenerator;

namespace AST {

struct Group;

struct Node {

  Parser *parser;
  Group *parent;

  Node(Parser *parser, Group *parent) : parser(parser), parent(parent) {}
  virtual ~Node() = default;

  static Node *parsing(Parser *parser, Group *parent,
                       std::list<TaggedToken> &taggedTokenList);

  virtual llvm::Value *codegen(CodeGenerator *codeGenerator) = 0;
  virtual void print(std::ostream &os, int indent = 0) const = 0;

  friend std::ostream &operator<<(std::ostream &os, const AST::Node &node);
};

} // namespace AST
