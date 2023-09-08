#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "Empty.h"

using namespace std;

namespace CombinatorUtil::Node {

std::string Empty::to_string() { return "empty"; }

bool Empty::equal(Node *node) { return true; };

} // namespace CombinatorUtil::Node