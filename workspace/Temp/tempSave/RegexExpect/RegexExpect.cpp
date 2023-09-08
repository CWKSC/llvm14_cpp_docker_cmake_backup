
#include <RegexUtil/include.h>
#include <include_std.h>

#include "../LexerCombinator/LexerCombinator.h"
#include "../Token/PureToken/PureToken.h"

#include "RegexExpect.h"

using namespace std;
using namespace RegexUtil;

namespace LexerCombinatorUtil {

RegexExpect::RegexExpect(const std::string &expectRegexString)
    : expectRegexString(expectRegexString) {}

Token::PureToken *RegexExpect::parsing(LexerCombinator &root,
                                       LexerCombinator &parent,
                                       std::string &text) {
  auto result = regexSearchInFront(expectRegexString, text);
  if (!result.isMatch) {
    std::cout << "except [" << expectRegexString << "] fail" << std::endl;
    return nullptr;
  }
  auto matchString = result.matchString;
  std::cout << "except [" << expectRegexString << "] matchString: ["
            << matchString << "]" << std::endl;
  text.erase(0, matchString.length());
  return new Token::PureToken(matchString);
}

} // namespace LexerCombinatorUtil
