#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "Any.h"

using namespace std;

namespace CombinatorUtil::Node {

std::string Any::to_string() { return "any"; }

bool Any::equal(Node *node) { return true; }

} // namespace CombinatorUtil::Node