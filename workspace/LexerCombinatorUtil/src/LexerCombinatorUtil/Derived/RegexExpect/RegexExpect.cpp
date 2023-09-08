#include <CombinatorUtil/include.h>
#include <ListTreeUtil/include.h>
#include <RegexUtil/include.h>
#include <include_std.h>

#include "../../LexerCombinator/LexerCombinator.h"

#include "RegexExpect.h"

using namespace std;
using namespace ListTreeUtil;
using namespace CombinatorUtil;
using namespace RegexUtil;

namespace LexerCombinatorUtil {

RegexExpect::RegexExpect(const std::string &regexString)
    : regexString(regexString) {}

ListTreeUtil::String *RegexExpect::lexing(Combinator &root, Combinator &parent,
                                          ListTreeUtil::String &text) {
  auto result = regexSearchInFront(regexString, text.value);
  if (!result.isMatch) {
    std::cout << "except [" << regexString << "] fail" << std::endl;
    return nullptr;
  }
  auto matchString = result.matchString;
  std::cout << "except [" << regexString << "] matchString: [" << matchString
            << "]" << std::endl;
  text.value.erase(0, matchString.length());
  return new ListTreeUtil::String(matchString);
}

} // namespace LexerCombinatorUtil
