#pragma once
#include <include_std.h>

#include "../../Node/Node.h"

namespace ListTreeUtil {

struct Char : Node {
  char value;
  Char(char value);
  bool equal(Node *node) override;
  std::string to_string() override;
};

} // namespace ListTreeUtil
