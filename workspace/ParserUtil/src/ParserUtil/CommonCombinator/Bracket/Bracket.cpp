#include <CombinatorUtil/include.h>
#include <ParserCombinatorUtil/include.h>
#include <include_std.h>

#include "Bracket.h"

using namespace CombinatorUtil;
using namespace ParserCombinatorUtil;

namespace ParserUtil {
using ParserCombinatorUtil::Expect;

ListTreeUtil::Node *Bracket::parsing(CombinatorUtil::Combinator &root,
                                     CombinatorUtil::Combinator &parent,
                                     ListTreeUtil::StringList &list) {
  return (new Or({
              new Expect("("),
              new Expect(")"),
              new Expect("{"),
              new Expect("}"),
              new Expect("["),
              new Expect("]"),
          }))
      ->parsing(root, *this, list);
}

} // namespace ParserUtil