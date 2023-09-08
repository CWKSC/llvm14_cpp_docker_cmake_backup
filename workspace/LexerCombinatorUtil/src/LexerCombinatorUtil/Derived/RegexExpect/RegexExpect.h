#pragma once
#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "../../LexerCombinator/LexerCombinator.h"

namespace LexerCombinatorUtil {

struct RegexExpect : LexerCombinator {
  const std::string regexString;
  RegexExpect(const std::string &regexString);
  ListTreeUtil::String *lexing(Combinator &root, Combinator &parent,
                               ListTreeUtil::String &text) override;
};

} // namespace LexerCombinatorUtil