#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "../../Combinator/Combinator.h"
#include "../../Node/Any/Any.h"

#include "Any.h"

using namespace std;

namespace CombinatorUtil {

Node::Any *Any::parsing(Combinator &root, Combinator &parent,
                        ListTreeUtil::IList &list) {
  if (list.empty()) {
    std::cout << "expect Any, but text is empty" << std::endl;
    return nullptr;
  }
  auto front = list.front();
  list.pop_front();
  return new Node::Any;
}

} // namespace CombinatorUtil
