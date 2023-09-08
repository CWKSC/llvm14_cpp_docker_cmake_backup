#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "../../Combinator/Combinator.h"
#include "../And_/And_.h"
#include "../Many/Many.h"

#include "UntilPeek.h"

using namespace std;

namespace CombinatorUtil {

UntilPeek::UntilPeek(Combinator *combinator, Combinator *until)
    : combinator(combinator), until(until) {}

ListTreeUtil::List *UntilPeek::parsing(Combinator &root, Combinator &parent,
                                       ListTreeUtil::IList &list) {
  auto *result = new ListTreeUtil::List;
  while (true) {
    if (list.empty())
      return nullptr;
    auto &cloneList = *list.clone();
    auto peek = until->parsing(root, *this, list);
    if (peek != nullptr) {
      result->push_back(peek);
      return result;
    } else {
      list.replaceBy(cloneList);
    }
    auto node = combinator->parsing(root, *this, list);
    if (node == nullptr) {
      return result;
    }
    result->push_back(node);
  }
  return nullptr;
}

} // namespace CombinatorUtil
