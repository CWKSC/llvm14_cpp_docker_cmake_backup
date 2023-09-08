#pragma once

#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "../../Parsing/parsing.h"
#include "../../Token/TaggedToken/TaggedToken.h"

#include "../Integer/Integer.h"
#include "../Node/Node.h"
#include "../Variable/Variable.h"

#include "llvm/IR/Value.h"

namespace AST {

struct For : Node {
  Variable *variable;
  Integer *init;
  Integer *upperLimit;
  Integer *step;
  Group *body;

  For(Parser *parser, Group *parent) : Node(parser, parent) {}
  ~For();

  static For *parsing(Parser *parser, Group *parent,
                      std::list<TaggedToken> &taggedTokenList);
  llvm::Value *codegen(CodeGenerator *codeGenerator);
  void print(std::ostream &os, int indent = 0) const;
};

} // namespace AST
