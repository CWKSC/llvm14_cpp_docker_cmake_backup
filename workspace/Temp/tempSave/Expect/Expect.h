#pragma once

#include <include_std.h>

#include "../LexerCombinator/LexerCombinator.h"
#include "../Token/PureToken/PureToken.h"

namespace LexerCombinatorUtil {

struct Expect : LexerCombinator {
  const std::string expectString;
  Expect(const std::string &expectString);
  Token::PureToken *parsing(LexerCombinator &root, LexerCombinator &parent,
                            std::string &text) override;
};

} // namespace LexerCombinatorUtil