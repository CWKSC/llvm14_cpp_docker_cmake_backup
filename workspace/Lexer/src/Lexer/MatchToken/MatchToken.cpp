
#include <LexerCombinatorUtil/include.h>

#include "MatchToken.h"

using namespace LexerCombinatorUtil;

namespace LexerUtil {

Token::Base *MatchToken::parsing(LexerCombinator &root, LexerCombinator &parent,
                                 std::string &text) {
  return (new Or({new Space, new NextLine, new Bracket, new Comma,
                  new LineComment("//"), new Literal, new Identifier}))
      ->parsing(root, *this, text);
}

} // namespace LexerUtil