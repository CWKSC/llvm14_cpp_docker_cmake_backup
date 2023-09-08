#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "../../Combinator/Combinator.h"

#include "And_.h"

using namespace std;

namespace CombinatorUtil {

And::And(std::vector<Combinator *> combinatorList)
    : combinatorList(combinatorList) {}

ListTreeUtil::List *And::parsing(Combinator &root, Combinator &parent,
                                 ListTreeUtil::IList &list) {
  auto *result = new ListTreeUtil::List;
  for (auto combinator : combinatorList) {
    auto node = combinator->parsing(root, *this, list);
    if (node != nullptr) {
      result->push_back(node);
    } else {
      return nullptr;
    }
  }
  return result;
}

} // namespace CombinatorUtil
