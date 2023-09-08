#include <CombinatorUtil/include.h>
#include <LexerCombinatorUtil/include.h>
#include <include_std.h>

#include "../Float/Float.h"
#include "../Integer/Integer.h"
#include "../String_/String_.h"

#include "Literal.h"

using namespace CombinatorUtil;
using namespace LexerCombinatorUtil;

namespace LexerUtil {

ListTreeUtil::Node *Literal::lexing(CombinatorUtil::Combinator &root,
                                    CombinatorUtil::Combinator &parent,
                                    ListTreeUtil::String &text) {
  return (new Or({new Float, new Integer, new String}))
      ->parsing(root, *this, text);
}

} // namespace LexerUtil