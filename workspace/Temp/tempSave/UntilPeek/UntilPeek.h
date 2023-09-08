#pragma once

#include <include_std.h>

#include "../LexerCombinator/LexerCombinator.h"
#include "../Token/Sequence/Sequence.h"

namespace LexerCombinatorUtil {

struct UntilPeek : LexerCombinator {
  LexerCombinator *parserCombinator;
  LexerCombinator *until;
  UntilPeek(LexerCombinator *parserCombinator, LexerCombinator *until);
  Token::Sequence *parsing(LexerCombinator &root, LexerCombinator &parent,
                           std::string &text) override;
};

} // namespace LexerCombinatorUtil