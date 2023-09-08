#pragma once

#include <include_std.h>

#include "../Node/Node.h"

namespace ListTreeUtil {

struct IList : Node {
  virtual bool empty() = 0;
  virtual Node *front() = 0;

  virtual void pop_front() = 0;
  virtual void pop_back() = 0;

  virtual IList *clone() = 0;
  virtual void clear() = 0;

  virtual void replaceBy(IList &list) = 0;
};

} // namespace ListTreeUtil