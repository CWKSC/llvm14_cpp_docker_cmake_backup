#pragma once

#include <iostream>
#include <list>

#include "../../Token/TaggedToken/TaggedToken.h"
#include "../Node/Node.h"

#include "llvm/IR/Value.h"

struct ParsingContext;

namespace AST {

struct Group;

struct NotMatch : Node {
  std::string string;

  NotMatch(Parser *parser, Group *parent, std::string _string)
      : Node(parser, parent) {
    string = _string;
  }
  ~NotMatch();

  llvm::Value *codegen(CodeGenerator *codeGenerator);
  void print(std::ostream &os, int indent = 0) const;
};

} // namespace AST
