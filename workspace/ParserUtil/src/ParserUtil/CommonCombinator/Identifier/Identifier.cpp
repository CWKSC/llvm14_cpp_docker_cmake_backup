
#include <CombinatorUtil/include.h>
#include <ParserCombinatorUtil/include.h>
#include <include_std.h>

#include "Identifier.h"

using namespace CombinatorUtil;
using namespace ParserCombinatorUtil;

namespace ParserUtil {

ListTreeUtil::Node *Identifier::parsing(CombinatorUtil::Combinator &root,
                                        CombinatorUtil::Combinator &parent,
                                        ListTreeUtil::StringList &list) {
  return (new RegexExpect("\\w\\w*"))->parsing(root, *this, list);
}

} // namespace ParserUtil
