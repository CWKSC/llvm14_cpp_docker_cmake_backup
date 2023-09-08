#pragma once

#include <include_std.h>

#include "../LexerCombinator/LexerCombinator.h"
#include "../Token/Sequence/Sequence.h"

namespace LexerCombinatorUtil {

struct And : LexerCombinator {
  std::vector<LexerCombinator *> parserCombinatorList;
  And(std::vector<LexerCombinator *> parserCombinatorList);
  Token::Sequence *parsing(LexerCombinator &root, LexerCombinator &parent,
                           std::string &text) override;
};

} // namespace LexerCombinatorUtil