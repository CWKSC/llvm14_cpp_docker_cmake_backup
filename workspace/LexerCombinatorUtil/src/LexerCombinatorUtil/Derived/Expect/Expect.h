#pragma once
#include <CombinatorUtil/include.h>
#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "../../LexerCombinator/LexerCombinator.h"

namespace LexerCombinatorUtil {

struct Expect : LexerCombinator {
  const std::string expectString;
  Expect(const std::string &expectString);
  ListTreeUtil::String *lexing(CombinatorUtil::Combinator &root,
                               CombinatorUtil::Combinator &parent,
                               ListTreeUtil::String &text) override;
};

} // namespace LexerCombinatorUtil