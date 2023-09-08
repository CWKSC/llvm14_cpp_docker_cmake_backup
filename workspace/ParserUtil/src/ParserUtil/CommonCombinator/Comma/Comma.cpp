#include <CombinatorUtil/include.h>
#include <ParserCombinatorUtil/include.h>
#include <include_std.h>

#include "Comma.h"

using namespace CombinatorUtil;
using namespace ParserCombinatorUtil;

namespace ParserUtil {
using ParserCombinatorUtil::Expect;

ListTreeUtil::Node *Comma::parsing(CombinatorUtil::Combinator &root,
                                   CombinatorUtil::Combinator &parent,
                                   ListTreeUtil::StringList &list) {
  return (new Expect(","))->parsing(root, *this, list);
}

} // namespace ParserUtil