#include <CombinatorUtil/include.h>
#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "../../ParserCombinator/ParserCombinator.h"

#include "Expect.h"

using namespace std;
using namespace CombinatorUtil;
using namespace ListTreeUtil;

namespace ParserCombinatorUtil {

Expect::Expect(const std::string &expectString) : expectString(expectString) {}

ListTreeUtil::Node *Expect::parsing(Combinator &root, Combinator &parent,
                                    ListTreeUtil::StringList &list) {
  auto front = list.front();
  if (!front->equal(new String(expectString))) {
    std::cout << "except [" << expectString << "] fail, actual ["
              << front->to_string() << "]" << std::endl;
    return nullptr;
  }
  std::cout << "except [" << expectString << "]" << std::endl;
  list.pop_front();
  return front;
}

} // namespace ParserCombinatorUtil
