#pragma once

#include <LexerCombinatorUtil/include.h>

namespace LexerUtil {

struct MatchToken : LexerCombinatorUtil::LexerCombinator {
  LexerCombinatorUtil::Token::Base *
  parsing(LexerCombinatorUtil::LexerCombinator &root,
          LexerCombinatorUtil::LexerCombinator &parent, std::string &text);
};

} // namespace LexerUtil
