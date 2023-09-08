#pragma once

#include "../../LexerCombinator/LexerCombinator.h"

namespace LexerCombinatorUtil {

struct LineComment : LexerCombinator {
  std::string startString;
  LineComment(std::string startString);
  Token::Base *parsing(LexerCombinator &root, LexerCombinator &parent,
                       std::string &text);
};

} // namespace LexerCombinatorUtil
