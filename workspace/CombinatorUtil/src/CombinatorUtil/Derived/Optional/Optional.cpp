#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "../../Combinator/Combinator.h"

#include "Optional.h"

using namespace std;

namespace CombinatorUtil {

Optional::Optional(Combinator *combinator) : combinator(combinator) {}

ListTreeUtil::Node *Optional::parsing(Combinator &root, Combinator &parent,
                                      ListTreeUtil::IList &list) {
  auto node = combinator->parsing(root, *this, list);
  if (node == nullptr) {
    return (ListTreeUtil::Node *)new ListTreeUtil::Null;
  }
  return (ListTreeUtil::Node *)node;
}

} // namespace CombinatorUtil
