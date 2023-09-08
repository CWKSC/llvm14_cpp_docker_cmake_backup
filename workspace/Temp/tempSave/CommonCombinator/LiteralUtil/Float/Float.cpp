#include <include_std.h>

#include "../../../LexerCombinator/LexerCombinator.h"
#include "../../../RegexExpect/RegexExpect.h"

#include "Float.h"

namespace LexerCombinatorUtil {

Token::Base *Float::parsing(LexerCombinator &root, LexerCombinator &parent,
                            std::string &text) {
  return (new RegexExpect("[+-]?\\d*\\.\\d*"))->parsing(root, *this, text);
}

} // namespace LexerCombinatorUtil