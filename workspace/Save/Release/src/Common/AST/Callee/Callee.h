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

struct Callee : Node {
  std::string name;
  std::vector<Node *> args;

  Callee(Parser *parser, Group *parent) : Node(parser, parent) {}
  ~Callee();

  static Callee *parsing(Parser *parser, Group *parent,
                         std::list<TaggedToken> &taggedTokenList);
  llvm::Value *codegen(CodeGenerator *codeGenerator);
  void print(std::ostream &os, int indent = 0) const;
};

} // namespace AST
