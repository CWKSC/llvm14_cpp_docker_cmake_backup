#pragma once

#include <include_std.h>

#include "../LexerCombinator/LexerCombinator.h"
#include "../Token/Sequence/Sequence.h"

namespace LexerCombinatorUtil {

struct Many : LexerCombinator {
  LexerCombinator *parserCombinator;
  Many(LexerCombinator *parserCombinator);
  Token::Sequence *parsing(LexerCombinator &root, LexerCombinator &parent,
                           std::string &text) override;
};

} // namespace LexerCombinatorUtil