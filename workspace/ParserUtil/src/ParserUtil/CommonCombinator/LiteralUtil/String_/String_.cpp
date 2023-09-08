#include <CombinatorUtil/include.h>
#include <ParserCombinatorUtil/include.h>
#include <include_std.h>

#include "String_.h"

using namespace CombinatorUtil;
using namespace ParserCombinatorUtil;

namespace ParserUtil {

ListTreeUtil::Node *String::parsing(CombinatorUtil::Combinator &root,
                                    CombinatorUtil::Combinator &parent,
                                    ListTreeUtil::StringList &list) {
  return (new RegexExpect("\\\"(\\\\.|[^\"\\\\])*\\\""))
      ->parsing(root, *this, list);
}

} // namespace ParserUtil
