
#include <include_std.h>

#include "../LexerCombinator/LexerCombinator.h"
#include "../Token/PureToken/PureToken.h"

#include "Any.h"

using namespace std;

namespace LexerCombinatorUtil {

Token::PureToken *Any::parsing(LexerCombinator &root, LexerCombinator &parent,
                               std::string &text) {
  if (text.empty()) {
    std::cout << "expect Any, but text is empty" << std::endl;
    return nullptr;
  }
  auto front = text.front();
  text.erase(0, 1);
  return new Token::PureToken(std::string{front});
}

} // namespace LexerCombinatorUtil
