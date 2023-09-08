#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "../../Combinator/Combinator.h"
#include "../Many/Many.h"

#include "OneOrMore.h"

using namespace std;

namespace CombinatorUtil {

OneOrMore::OneOrMore(Combinator *combinator) : combinator(combinator) {}

ListTreeUtil::List *OneOrMore::parsing(Combinator &root, Combinator &parent,
                                       ListTreeUtil::IList &list) {
  auto *result = new ListTreeUtil::List;
  auto node = combinator->parsing(root, *this, list);
  if (node == nullptr) {
    return nullptr;
  }
  result->push_back(node);
  auto nodeList = Many(combinator).parsing(root, *this, list);
  result->push_back(nodeList);
  return result;
}

} // namespace CombinatorUtil
