#include <CombinatorUtil/include.h>
#include <ListTreeUtil/include.h>
#include <ParserCombinatorUtil/include.h>
#include <include_std.h>

#include "Integer.h"

using namespace CombinatorUtil;
using namespace ParserCombinatorUtil;

namespace ParserUtil {

ListTreeUtil::Node *Integer::parsing(CombinatorUtil::Combinator &root,
                                     CombinatorUtil::Combinator &parent,
                                     ListTreeUtil::StringList &list) {
  return (new RegexExpect("[+-]?\\d+"))->parsing(root, *this, list);
}

} // namespace ParserUtil