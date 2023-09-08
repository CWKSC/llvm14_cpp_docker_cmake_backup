#include <iostream>
#include <string>

#include "BaseToken.h"

std::ostream &operator<<(std::ostream &os, const BaseToken &token) {
  os << "(string: " << token.string << ", line: " << token.line
     << ", position: " << token.position << ", length: " << token.length << ")";
  return os;
}
