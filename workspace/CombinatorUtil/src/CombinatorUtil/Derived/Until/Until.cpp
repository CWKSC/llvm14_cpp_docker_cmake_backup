#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "../../Combinator/Combinator.h"
#include "../And_/And_.h"
#include "../Many/Many.h"

#include "Until.h"

using namespace std;

namespace CombinatorUtil {

Until::Until(Combinator *combinator, Combinator *until)
    : combinator(combinator), until(until) {}

ListTreeUtil::List *Until::parsing(Combinator &root, Combinator &parent,
                                   ListTreeUtil::IList &list) {
  return (new And({new Many(combinator), until}))->parsing(root, *this, list);
}

} // namespace CombinatorUtil
