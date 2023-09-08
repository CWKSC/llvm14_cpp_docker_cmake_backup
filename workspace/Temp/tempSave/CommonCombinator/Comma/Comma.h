#pragma once

#include "../../LexerCombinator/LexerCombinator.h"

namespace LexerCombinatorUtil {

struct Comma : LexerCombinator {
  Token::Base *parsing(LexerCombinator &root, LexerCombinator &parent,
                       std::string &text);
};

} // namespace LexerCombinatorUtil
