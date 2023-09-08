#include <CombinatorUtil/include.h>
#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "../../ParserCombinator/ParserCombinator.h"

#include "Any.h"

using namespace std;

namespace ParserCombinatorUtil {

ListTreeUtil::Node *parsing(CombinatorUtil::Combinator &root,
                            CombinatorUtil::Combinator &parent,
                            ListTreeUtil::StringList &list) {
  if (list.empty()) {
    std::cout << "expect Any, but list is empty" << std::endl;
    return nullptr;
  }
  auto front = list.front();
  list.pop_front();
  return front;
}

} // namespace ParserCombinatorUtil
