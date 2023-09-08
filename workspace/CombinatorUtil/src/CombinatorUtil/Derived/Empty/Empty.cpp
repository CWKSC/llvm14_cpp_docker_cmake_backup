#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "../../Combinator/Combinator.h"
#include "../../Node/Empty/Empty.h"

#include "Empty.h"

using namespace std;

namespace CombinatorUtil {

Node::Empty *Empty::parsing(Combinator &root, Combinator &parent,
                            ListTreeUtil::IList &list) {
  return new Node::Empty;
}

} // namespace CombinatorUtil
