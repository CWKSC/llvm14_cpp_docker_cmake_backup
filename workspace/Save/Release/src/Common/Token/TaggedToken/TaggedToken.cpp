

#include <iostream>
#include <string>

#include "TaggedToken.h"

std::ostream &operator<<(std::ostream &os, const TaggedToken &token) {
  os << "(tag: " << token.tag << ", baseToken: " << token.baseToken;
  return os;
}
