#include <CombinatorUtil/include.h>
#include <ListTreeUtil/include.h>
#include <RegexUtil/include.h>
#include <include_std.h>

#include "../../ParserCombinator/ParserCombinator.h"

#include "RegexExpect.h"

using namespace std;
using namespace ListTreeUtil;
using namespace CombinatorUtil;
using namespace RegexUtil;

namespace ParserCombinatorUtil {

RegexExpect::RegexExpect(const std::string &regexString)
    : regexString(regexString) {}

ListTreeUtil::Node *RegexExpect::parsing(CombinatorUtil::Combinator &root,
                                         CombinatorUtil::Combinator &parent,
                                         ListTreeUtil::StringList &list) {
  auto front = list.front();
  auto result = regexMatch(regexString, front->value);
  if (!result.isMatch) {
    std::cout << "except [" << regexString << "] fail" << std::endl;
    return nullptr;
  }
  auto matchString = result.matchString;
  std::cout << "except [" << regexString << "] matchString: [" << matchString
            << "]" << std::endl;
  list.pop_front();
  return front;
}

} // namespace ParserCombinatorUtil
