#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "../../Combinator/Combinator.h"

#include "Many.h"

using namespace std;

namespace CombinatorUtil {

Many::Many(Combinator *combinator) : combinator(combinator) {}

ListTreeUtil::List *Many::parsing(Combinator &root, Combinator &parent,
                                  ListTreeUtil::IList &list) {
  auto *result = new ListTreeUtil::List;
  while (true) {
    auto node = combinator->parsing(root, *this, list);
    if (node == nullptr) {
      return result;
    }
    result->push_back(node);
  }
}

} // namespace CombinatorUtil
