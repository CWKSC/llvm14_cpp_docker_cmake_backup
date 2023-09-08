#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "../../Combinator/Combinator.h"

#include "Ref.h"

using namespace std;

namespace CombinatorUtil {

Ref::Ref(Combinator **combinatorAddress)
    : combinatorAddress(combinatorAddress) {}

ListTreeUtil::Node *Ref::parsing(Combinator &root, Combinator &parent,
                                 ListTreeUtil::IList &list) {
  return (*combinatorAddress)->parsing(root, parent, list);
}

} // namespace CombinatorUtil
