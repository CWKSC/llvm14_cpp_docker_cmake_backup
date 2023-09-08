#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "../../Combinator/Combinator.h"

#include "../And_/And_.h"
#include "../Many/Many.h"

#include "../Until/Until.h"

#include "AroundMany.h"

using namespace std;

namespace CombinatorUtil {

AroundMany::AroundMany(Combinator *before, Combinator *combinator,
                       Combinator *after)
    : before(before), combinator(combinator), after(after) {}

ListTreeUtil::List *AroundMany::parsing(Combinator &root, Combinator &parent,
                                        ListTreeUtil::IList &list) {
  return (new And({before, new Until(combinator, after)}))
      ->parsing(root, *this, list);
}

} // namespace CombinatorUtil
