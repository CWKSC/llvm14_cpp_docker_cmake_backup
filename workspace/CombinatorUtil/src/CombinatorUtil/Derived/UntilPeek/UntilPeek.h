#pragma once
#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "../../Combinator/Combinator.h"

namespace CombinatorUtil {

struct UntilPeek : Combinator {
  Combinator *combinator;
  Combinator *until;
  UntilPeek(Combinator *combinator, Combinator *until);
  ListTreeUtil::List *parsing(Combinator &root, Combinator &parent,
                              ListTreeUtil::IList &list) override;
};

} // namespace CombinatorUtil