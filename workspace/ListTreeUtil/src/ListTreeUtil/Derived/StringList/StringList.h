#pragma once
#include <include_std.h>

#include "../../IList/IList.h"

#include "../String_/String_.h"

namespace ListTreeUtil {

struct StringList : IList {
  std::list<std::string> value;
  StringList(std::list<std::string> value);

  // Override function
  bool empty() override;
  String *front() override;
  void pop_front() override;
  void pop_back() override;
  void clear() override;
  StringList *clone() override;
  void replaceBy(IList &list) override;
  bool equal(Node *node) override;
  std::string to_string() override;
};

} // namespace ListTreeUtil
