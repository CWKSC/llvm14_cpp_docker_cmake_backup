#pragma once

#include "../../LexerCombinator/LexerCombinator.h"

#include "../Token/Space/Space.h"

namespace LexerCombinatorUtil {

struct Space : LexerCombinator {
  Token::Space *parsing(LexerCombinator &root, LexerCombinator &parent,
                        std::string &text);
};

} // namespace LexerCombinatorUtil
