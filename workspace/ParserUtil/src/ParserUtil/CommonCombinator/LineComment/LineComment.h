#pragma once
#include <CombinatorUtil/include.h>
#include <ParserCombinatorUtil/include.h>
#include <include_std.h>

namespace ParserUtil {

struct LineComment : ParserCombinatorUtil::ParserCombinator {
  std::string startString;
  LineComment(std::string startString);
  ListTreeUtil::Node *parsing(CombinatorUtil::Combinator &root,
                              CombinatorUtil::Combinator &parent,
                              ListTreeUtil::StringList &list);
};

} // namespace ParserUtil
