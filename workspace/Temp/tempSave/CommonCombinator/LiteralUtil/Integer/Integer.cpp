#include <include_std.h>

#include "../../../LexerCombinator/LexerCombinator.h"
#include "../../../RegexExpect/RegexExpect.h"

#include "Integer.h"

namespace LexerCombinatorUtil {

Token::Base *Integer::parsing(LexerCombinator &root, LexerCombinator &parent,
                              std::string &text) {
  return (new RegexExpect("[+-]?\\d+"))->parsing(root, *this, text);
}

} // namespace LexerCombinatorUtil