#pragma once
#include <CombinatorUtil/include.h>
#include <LexerCombinatorUtil/include.h>
#include <include_std.h>

namespace LexerUtil {

struct String : LexerCombinatorUtil::LexerCombinator {
  ListTreeUtil::Node *lexing(CombinatorUtil::Combinator &root,
                             CombinatorUtil::Combinator &parent,
                             ListTreeUtil::String &text);
};

} // namespace LexerUtil
