#include <CombinatorUtil/include.h>
#include <ParserCombinatorUtil/include.h>
#include <include_std.h>

#include "LineComment.h"

using namespace CombinatorUtil;
using namespace ParserCombinatorUtil;

namespace ParserUtil {
using ParserCombinatorUtil::Expect;

LineComment::LineComment(std::string startString) : startString(startString) {}

ListTreeUtil::Node *LineComment::parsing(CombinatorUtil::Combinator &root,
                                         CombinatorUtil::Combinator &parent,
                                         ListTreeUtil::StringList &list) {
  return (new And({new Expect(startString), new RegexExpect(".*\n")}))
      ->parsing(root, *this, list);
}

} // namespace ParserUtil