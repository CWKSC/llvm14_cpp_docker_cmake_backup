#pragma once
#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "../../Combinator/Combinator.h"

namespace CombinatorUtil {

struct Or : Combinator {
  std::vector<Combinator *> combinatorList;
  Or(std::vector<Combinator *> combinatorList);
  ListTreeUtil::Node *parsing(Combinator &root, Combinator &parent,
                              ListTreeUtil::IList &list) override;
};

} // namespace CombinatorUtil