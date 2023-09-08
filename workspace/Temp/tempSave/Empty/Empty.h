#pragma once

#include <include_std.h>

#include "../LexerCombinator/LexerCombinator.h"

namespace LexerCombinatorUtil {

struct Empty : LexerCombinator {
  Token::Empty *parsing(LexerCombinator &root, LexerCombinator &parent,
                        std::string &text) override;
};

} // namespace LexerCombinatorUtil