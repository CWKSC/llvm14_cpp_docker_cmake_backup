#pragma once
#include <include_std.h>

#include "../../IList/IList.h"

#include "../Char/Char.h"

namespace ListTreeUtil {

struct String : IList {
  std::string value;

  String(std::string value);

  // Override function
  bool empty() override;
  Char *front() override;
  void pop_front() override;
  void pop_back() override;
  void clear() override;
  String *clone() override;
  void replaceBy(IList &list) override;

  bool equal(Node *node) override;
  std::string to_string() override;
};

} // namespace ListTreeUtil
