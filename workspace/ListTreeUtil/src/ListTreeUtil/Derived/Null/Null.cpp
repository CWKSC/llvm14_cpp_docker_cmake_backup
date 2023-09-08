#include <include_std.h>

#include "../../Node/Node.h"

#include "Null.h"

namespace ListTreeUtil {

bool Null::equal(Node *node) { return true; }

std::string Null::to_string() { return "null"; }

} // namespace ListTreeUtil