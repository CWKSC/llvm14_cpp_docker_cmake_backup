#pragma once

#include <include_std.h>

#include "../LexerCombinator/LexerCombinator.h"
#include "../Token/Base/Base.h"

namespace LexerCombinatorUtil {

struct Optional : LexerCombinator {
  LexerCombinator *parserCombinator;
  Optional(LexerCombinator *parserCombinator);
  Token::Base *parsing(LexerCombinator &root, LexerCombinator &parent,
                       std::string &text) override;
};

} // namespace LexerCombinatorUtil