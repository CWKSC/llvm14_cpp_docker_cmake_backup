#pragma once
#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "../../Combinator/Combinator.h"

namespace CombinatorUtil {

struct Until : Combinator {
  Combinator *combinator;
  Combinator *until;
  Until(Combinator *combinator, Combinator *until);
  ListTreeUtil::List *parsing(Combinator &root, Combinator &parent,
                              ListTreeUtil::IList &list) override;
};

} // namespace CombinatorUtil