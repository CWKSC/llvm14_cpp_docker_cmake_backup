
#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "LexerCombinator.h"

using namespace std;

namespace LexerCombinatorUtil {

ListTreeUtil::Node *LexerCombinator::parsing(Combinator &root,
                                             Combinator &parent,
                                             ListTreeUtil::IList &list) {
  return lexing(root, parent, dynamic_cast<ListTreeUtil::String &>(list));
}

} // namespace LexerCombinatorUtil
