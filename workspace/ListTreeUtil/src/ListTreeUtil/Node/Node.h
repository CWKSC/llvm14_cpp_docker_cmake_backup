#pragma once

#include <include_std.h>

namespace ListTreeUtil {

struct Node {
  virtual bool equal(Node *node) = 0;
  virtual std::string to_string() = 0;
  void print();
  void println();
};

} // namespace ListTreeUtil
