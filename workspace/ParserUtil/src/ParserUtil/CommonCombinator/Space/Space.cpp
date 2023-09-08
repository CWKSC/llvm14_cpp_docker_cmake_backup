#include <CombinatorUtil/include.h>
#include <ListTreeUtil/include.h>
#include <ParserCombinatorUtil/include.h>
#include <include_std.h>

#include "Space.h"

using namespace CombinatorUtil;
using namespace ParserCombinatorUtil;

namespace ParserUtil {
using ParserCombinatorUtil::Expect;

ListTreeUtil::Node *Space::parsing(CombinatorUtil::Combinator &root,
                                   CombinatorUtil::Combinator &parent,
                                   ListTreeUtil::StringList &list) {
  return (new RegexExpect(" +"))->parsing(root, *this, list);
}

} // namespace ParserUtil
