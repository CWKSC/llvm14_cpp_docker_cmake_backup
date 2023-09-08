
#include "../../LexerCombinator/LexerCombinator.h"
#include "../../RegexExpect/RegexExpect.h"

#include "Identifier.h"

namespace LexerCombinatorUtil {

Token::Base *Identifier::parsing(LexerCombinator &root, LexerCombinator &parent,
                                 std::string &text) {
  return (new RegexExpect("\\w\\w*"))->parsing(root, *this, text);
}

} // namespace LexerCombinatorUtil