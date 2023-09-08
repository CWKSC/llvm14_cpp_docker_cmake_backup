
#include <include_std.h>

#include "Node.h"

using namespace std;

namespace ListTreeUtil {

void Node::print() { std::cout << to_string(); }

void Node::println() {
  print();
  std::cout << '\n';
}

} // namespace ListTreeUtil