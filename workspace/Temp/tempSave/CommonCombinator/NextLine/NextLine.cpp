
#include "../../Expect/Expect.h"
#include "../../LexerCombinator/LexerCombinator.h"

#include "NextLine.h"

namespace LexerCombinatorUtil {

Token::Base *NextLine::parsing(LexerCombinator &root, LexerCombinator &parent,
                               std::string &text) {
  return (new Expect("\n"))->parsing(root, *this, text);
}

} // namespace LexerCombinatorUtil