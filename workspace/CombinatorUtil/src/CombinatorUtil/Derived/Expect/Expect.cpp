#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "../../Combinator/Combinator.h"
#include "../../Node/Empty/Empty.h"

#include "Expect.h"

using namespace std;

namespace CombinatorUtil {

Expect::Expect(ListTreeUtil::Node *expect) : expect(expect) {}

ListTreeUtil::Node *Expect::parsing(Combinator &root, Combinator &parent,
                                    ListTreeUtil::IList &list) {
  auto front = list.front();
  if (front->equal(expect)) {
    list.pop_front();
    return front;
  }
  return nullptr;
}

} // namespace CombinatorUtil
