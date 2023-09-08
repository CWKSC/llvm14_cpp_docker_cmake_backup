#pragma once
#include <CombinatorUtil/include.h>
#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "../../ParserCombinator/ParserCombinator.h"

namespace ParserCombinatorUtil {

struct RegexExpect : ParserCombinator {
  const std::string regexString;
  RegexExpect(const std::string &regexString);
  ListTreeUtil::Node *parsing(CombinatorUtil::Combinator &root,
                              CombinatorUtil::Combinator &parent,
                              ListTreeUtil::StringList &list) override;
};

} // namespace ParserCombinatorUtil