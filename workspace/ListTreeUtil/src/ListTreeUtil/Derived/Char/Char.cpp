#include <include_std.h>

#include "../../Node/Node.h"

#include "Char.h"

using namespace std;

namespace ListTreeUtil {

Char::Char(char value) : value(value){};

bool Char::equal(Node *node) {
  auto another = dynamic_cast<Char *>(node);
  if (another == nullptr)
    return false;
  return value == another->value;
}

std::string Char::to_string() { return string{value}; };

} // namespace ListTreeUtil