#include <include_std.h>

#include "../../../LexerCombinator/LexerCombinator.h"
#include "../../../RegexExpect/RegexExpect.h"

#include "String_.h"

namespace LexerCombinatorUtil {

Token::Base *String::parsing(LexerCombinator &root, LexerCombinator &parent,
                             std::string &text) {
  return (new RegexExpect("\\\"(\\\\.|[^\"\\\\])*\\\""))
      ->parsing(root, *this, text);
}

} // namespace LexerCombinatorUtil