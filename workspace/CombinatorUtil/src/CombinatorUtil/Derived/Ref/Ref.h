#pragma once
#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "../../Combinator/Combinator.h"

namespace CombinatorUtil {

struct Ref : Combinator {
  Combinator **combinatorAddress;
  Ref(Combinator **combinatorAddress);
  ListTreeUtil::Node *parsing(Combinator &root, Combinator &parent,
                              ListTreeUtil::IList &list) override;
};

} // namespace CombinatorUtil