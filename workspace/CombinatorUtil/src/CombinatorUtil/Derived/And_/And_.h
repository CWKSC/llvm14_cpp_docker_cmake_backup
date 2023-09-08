#pragma once
#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "../../Combinator/Combinator.h"

namespace CombinatorUtil {

struct And : Combinator {
  std::vector<Combinator *> combinatorList;
  And(std::vector<Combinator *> combinatorList);
  ListTreeUtil::List *parsing(Combinator &root, Combinator &parent,
                              ListTreeUtil::IList &list) override;
};

} // namespace CombinatorUtil