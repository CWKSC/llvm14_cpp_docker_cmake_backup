#pragma once
#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "../../Combinator/Combinator.h"
#include "../../Node/Empty/Empty.h"

namespace CombinatorUtil {

struct Expect : Combinator {
  ListTreeUtil::Node *expect;
  Expect(ListTreeUtil::Node *expect);
  ListTreeUtil::Node *parsing(Combinator &root, Combinator &parent,
                              ListTreeUtil::IList &list) override;
};

} // namespace CombinatorUtil