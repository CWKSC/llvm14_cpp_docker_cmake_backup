#pragma once
#include <CombinatorUtil/include.h>
#include <ListTreeUtil/include.h>
#include <ParserCombinatorUtil/include.h>
#include <include_std.h>

namespace ParserUtil {

struct Integer : ParserCombinatorUtil::ParserCombinator {
  ListTreeUtil::Node *parsing(CombinatorUtil::Combinator &root,
                              CombinatorUtil::Combinator &parent,
                              ListTreeUtil::StringList &list);
};

} // namespace ParserUtil
