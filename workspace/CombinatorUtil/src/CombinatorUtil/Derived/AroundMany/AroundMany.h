#pragma once
#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "../../Combinator/Combinator.h"

namespace CombinatorUtil {

struct AroundMany : Combinator {
  Combinator *before;
  Combinator *combinator;
  Combinator *after;
  AroundMany(Combinator *before, Combinator *combinator, Combinator *after);
  ListTreeUtil::List *parsing(Combinator &root, Combinator &parent,
                              ListTreeUtil::IList &list) override;
};

} // namespace CombinatorUtil