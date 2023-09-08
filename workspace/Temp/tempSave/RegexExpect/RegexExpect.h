#pragma once

#include <include_std.h>

#include "../LexerCombinator/LexerCombinator.h"
#include "../Token/PureToken/PureToken.h"

namespace LexerCombinatorUtil {

struct RegexExpect : LexerCombinator {
  const std::string expectRegexString;
  RegexExpect(const std::string &expectRegexString);
  Token::PureToken *parsing(LexerCombinator &root, LexerCombinator &parent,
                            std::string &text) override;
};

} // namespace LexerCombinatorUtil