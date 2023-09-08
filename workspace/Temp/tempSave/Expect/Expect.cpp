
#include <include_std.h>

#include "../LexerCombinator/LexerCombinator.h"
#include "../Token/PureToken/PureToken.h"

#include "Expect.h"

using namespace std;

namespace LexerCombinatorUtil {

Expect::Expect(const std::string &expectString) : expectString(expectString) {}

Token::PureToken *Expect::parsing(LexerCombinator &root,
                                  LexerCombinator &parent, std::string &text) {
  // Not start with
  if (text.rfind(expectString, 0) != 0) {
    std::cout << "except [" << expectString << "] fail" << std::endl;
    return nullptr;
  }
  std::cout << "except [" << expectString << "]" << std::endl;
  text.erase(0, expectString.length());
  return new Token::PureToken(expectString);
}

} // namespace LexerCombinatorUtil
