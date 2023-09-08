
#include <include_std.h>

#include "InterfaceUtil/include.h"

using namespace std;
using namespace InterfaceUtil;

struct Element : IEqual<Element>, IToString {
  int value;
  Element(int value) : value(value) {}
  bool equal(Element other) { return value == other.value; }
  std::string to_string() { return std::to_string(value); }
};

int main() {

  Element a{1};
  Element b{2};
  Element c{1};

  std::cout << "a.to_string(): " << a.to_string() << std::endl;
  std::cout << "b.to_string(): " << b.to_string() << std::endl;
  std::cout << "c.to_string(): " << c.to_string() << std::endl;
  std::cout << std::endl;

  std::cout << "a.equal(b): " << a.equal(b) << std::endl;
  std::cout << "a.equal(c): " << a.equal(c) << std::endl;
  std::cout << "b.equal(c): " << b.equal(c) << std::endl;
  std::cout << "c.equal(a): " << c.equal(a) << std::endl;

  return 0;
}
