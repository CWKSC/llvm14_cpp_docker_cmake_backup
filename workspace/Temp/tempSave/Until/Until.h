#pragma once

#include <include_std.h>

#include "../LexerCombinator/LexerCombinator.h"
#include "../Token/Sequence/Sequence.h"

namespace LexerCombinatorUtil {

struct Until : LexerCombinator {
  LexerCombinator *parserCombinator;
  LexerCombinator *until;
  Until(LexerCombinator *parserCombinator, LexerCombinator *until);
  Token::Sequence *parsing(LexerCombinator &root, LexerCombinator &parent,
                           std::string &text) override;
};

} // namespace LexerCombinatorUtil