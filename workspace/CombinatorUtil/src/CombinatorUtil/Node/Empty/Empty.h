#pragma once
#include <ListTreeUtil/include.h>
#include <include_std.h>

namespace CombinatorUtil::Node {

struct Empty : ListTreeUtil::Node {
  bool equal(ListTreeUtil::Node *node) override;
  std::string to_string() override;
};

} // namespace CombinatorUtil::Node
