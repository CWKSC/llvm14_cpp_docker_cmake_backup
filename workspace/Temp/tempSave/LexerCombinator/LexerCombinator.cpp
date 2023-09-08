
#include <include_std.h>

#include "LexerCombinator.h"

using namespace std;

namespace LexerCombinatorUtil {

ListTreeUtil::Node *LexerCombinator::parsing(Combinator &root,
                                             Combinator &parent,
                                             ListTreeUtil::List &list) {
  auto text = list.to_string();
  return lexing(root, parent, text);
}

} // namespace LexerCombinatorUtil
