#include <CombinatorUtil/include.h>
#include <ListTreeUtil/include.h>
#include <ParserCombinatorUtil/include.h>
#include <include_std.h>

#include "../Float/Float.h"
#include "../Integer/Integer.h"
#include "../String_/String_.h"

#include "Literal.h"

using namespace CombinatorUtil;
using namespace ParserCombinatorUtil;

namespace ParserUtil {

ListTreeUtil::Node *Literal::parsing(CombinatorUtil::Combinator &root,
                                     CombinatorUtil::Combinator &parent,
                                     ListTreeUtil::StringList &list) {
  return (new Or({new Float, new Integer, new String}))
      ->parsing(root, *this, list);
}

} // namespace ParserUtil