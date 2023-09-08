#pragma once
#include <CombinatorUtil/include.h>
#include <ParserCombinatorUtil/include.h>
#include <include_std.h>

namespace ParserUtil {

struct Identifier : ParserCombinatorUtil::ParserCombinator {
  ListTreeUtil::Node *parsing(CombinatorUtil::Combinator &root,
                              CombinatorUtil::Combinator &parent,
                              ListTreeUtil::StringList &list) override;
};

} // namespace ParserUtil
