#pragma once

namespace AST {
struct Group;
}

struct ParsingResult {
  AST::Group *root;
  ParsingResult(AST::Group *root) : root(root) {}
};
