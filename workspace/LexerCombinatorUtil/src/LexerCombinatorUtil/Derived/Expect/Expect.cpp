#include <CombinatorUtil/include.h>
#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "../../LexerCombinator/LexerCombinator.h"

#include "Expect.h"

using namespace std;
using namespace CombinatorUtil;

namespace LexerCombinatorUtil {

Expect::Expect(const std::string &expectString) : expectString(expectString) {}

ListTreeUtil::String *Expect::lexing(Combinator &root, Combinator &parent,
                                     ListTreeUtil::String &text) {
  // Not start with
  if (text.value.rfind(expectString, 0) != 0) {
    std::cout << "except [" << expectString << "] fail" << std::endl;
    return nullptr;
  }
  std::cout << "except [" << expectString << "]" << std::endl;
  text.value.erase(0, expectString.length());
  return new ListTreeUtil::String(expectString);
}

} // namespace LexerCombinatorUtil
