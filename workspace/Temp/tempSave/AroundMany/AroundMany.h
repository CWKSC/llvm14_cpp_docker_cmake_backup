#pragma once

#include <include_std.h>

#include "../LexerCombinator/LexerCombinator.h"
#include "../Token/Sequence/Sequence.h"

namespace LexerCombinatorUtil {

struct AroundMany : LexerCombinator {
  LexerCombinator *before;
  LexerCombinator *parserCombinator;
  LexerCombinator *after;
  AroundMany(LexerCombinator *before, LexerCombinator *parserCombinator,
             LexerCombinator *after);
  Token::Sequence *parsing(LexerCombinator &root, LexerCombinator &parent,
                           std::string &text) override;
};

} // namespace LexerCombinatorUtil