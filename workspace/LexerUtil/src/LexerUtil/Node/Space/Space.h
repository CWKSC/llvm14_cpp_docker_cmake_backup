#pragma once

#include <LexerCombinatorUtil/include.h>
#include <ListTreeUtil/include.h>
#include <include_std.h>

namespace LexerUtil::Node {

struct Space : ListTreeUtil::Node {
  std::string value;
  Space(std::string value);
  bool equal(ListTreeUtil::Node *node) override;
  std::string to_string() override;
};

} // namespace LexerUtil::Node
