#include <CombinatorUtil/include.h>
#include <LexerCombinatorUtil/include.h>
#include <include_std.h>

#include "Bracket.h"

using namespace CombinatorUtil;
using namespace LexerCombinatorUtil;

namespace LexerUtil {
using LexerCombinatorUtil::Expect;

ListTreeUtil::Node *Bracket::lexing(CombinatorUtil::Combinator &root,
                                    CombinatorUtil::Combinator &parent,
                                    ListTreeUtil::String &text) {
  return (new Or({
              new Expect("("),
              new Expect(")"),
              new Expect("{"),
              new Expect("}"),
              new Expect("["),
              new Expect("]"),
          }))
      ->parsing(root, *this, text);
}

} // namespace LexerUtil