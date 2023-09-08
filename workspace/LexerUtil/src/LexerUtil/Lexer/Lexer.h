#pragma once
#include <CombinatorUtil/include.h>
#include <LexerCombinatorUtil/include.h>
#include <ListTreeUtil/include.h>

namespace LexerUtil {

struct Lexer : LexerCombinatorUtil::LexerCombinator {
  LexerCombinatorUtil::LexerCombinator *matchToken;
  Lexer(LexerCombinatorUtil::LexerCombinator *matchToken);
  ListTreeUtil::Node *lexing(CombinatorUtil::Combinator &root,
                             CombinatorUtil::Combinator &parent,
                             ListTreeUtil::String &text);
};

} // namespace LexerUtil
