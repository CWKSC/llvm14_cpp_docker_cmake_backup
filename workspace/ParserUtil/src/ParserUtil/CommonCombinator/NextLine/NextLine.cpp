#include <CombinatorUtil/include.h>
#include <ListTreeUtil/include.h>
#include <ParserCombinatorUtil/include.h>
#include <include_std.h>

#include "NextLine.h"

using namespace CombinatorUtil;
using namespace ParserCombinatorUtil;

namespace ParserUtil {
using ParserCombinatorUtil::Expect;

ListTreeUtil::Node *NextLine::parsing(CombinatorUtil::Combinator &root,
                                      CombinatorUtil::Combinator &parent,
                                      ListTreeUtil::StringList &list) {
  return (new Expect("\n"))->parsing(root, *this, list);
}

} // namespace ParserUtil
