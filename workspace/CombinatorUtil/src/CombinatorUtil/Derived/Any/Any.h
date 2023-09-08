#pragma once
#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "../../Combinator/Combinator.h"

namespace CombinatorUtil {

struct Any : Combinator {
  Node::Any *parsing(Combinator &root, Combinator &parent,
                     ListTreeUtil::IList &list) override;
};

} // namespace CombinatorUtil