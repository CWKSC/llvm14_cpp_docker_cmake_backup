#pragma once

#include <include_std.h>

#include "../LexerCombinator/LexerCombinator.h"
#include "../Token/PureToken/PureToken.h"

namespace LexerCombinatorUtil {

struct Any : LexerCombinator {
  Token::PureToken *parsing(LexerCombinator &root, LexerCombinator &parent,
                            std::string &text) override;
};

} // namespace LexerCombinatorUtil