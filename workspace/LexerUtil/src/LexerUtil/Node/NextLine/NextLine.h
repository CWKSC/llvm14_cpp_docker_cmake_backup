#pragma once

#include <ListTreeUtil/include.h>
#include <include_std.h>

namespace LexerUtil::Node {

struct NextLine : ListTreeUtil::Node {
  bool equal(ListTreeUtil::Node *node) override;
  std::string to_string() override;
};

} // namespace LexerUtil::Node
