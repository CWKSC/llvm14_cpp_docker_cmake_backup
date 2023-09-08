
#include "../../Expect/Expect.h"
#include "../../LexerCombinator/LexerCombinator.h"

#include "Comma.h"

namespace LexerCombinatorUtil {

Token::Base *Comma::parsing(LexerCombinator &root, LexerCombinator &parent,
                            std::string &text) {
  return (new Expect(","))->parsing(root, *this, text);
}

} // namespace LexerCombinatorUtil