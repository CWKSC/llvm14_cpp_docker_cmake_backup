#include <CombinatorUtil/include.h>
#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "ParserCombinator.h"

using namespace std;

namespace ParserCombinatorUtil {

ListTreeUtil::Node *
ParserCombinator::parsing(CombinatorUtil::Combinator &root,
                          CombinatorUtil::Combinator &parent,
                          ListTreeUtil::IList &list) {
  return parsing(root, parent, dynamic_cast<ListTreeUtil::StringList &>(list));
}

} // namespace ParserCombinatorUtil
