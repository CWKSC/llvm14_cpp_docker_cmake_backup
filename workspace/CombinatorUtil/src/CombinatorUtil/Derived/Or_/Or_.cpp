#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "../../Combinator/Combinator.h"

#include "Or_.h"

using namespace std;

namespace CombinatorUtil {

Or::Or(vector<Combinator *> combinatorList) : combinatorList(combinatorList) {}

ListTreeUtil::Node *Or::parsing(Combinator &root, Combinator &parent,
                                ListTreeUtil::IList &list) {
  for (auto &combinator : combinatorList) {
    auto &cloneList = *list.clone();
    auto node = combinator->parsing(root, *this, cloneList);
    if (node != nullptr) {
      list.replaceBy(cloneList);
      return node;
    }
  }
  return nullptr;
}

} // namespace CombinatorUtil
