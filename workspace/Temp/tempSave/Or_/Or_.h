#pragma once

#include <include_std.h>

#include "../LexerCombinator/LexerCombinator.h"
#include "../Token/Base/Base.h"

namespace LexerCombinatorUtil {

struct Or : LexerCombinator {
  std::vector<LexerCombinator *> parserCombinatorList;
  Or(std::vector<LexerCombinator *> parserCombinatorList);
  Token::Base *parsing(LexerCombinator &root, LexerCombinator &parent,
                       std::string &text) override;
};

} // namespace LexerCombinatorUtil