#include <include_std.h>

#include "../Char/Char.h"

#include "String_.h"

using namespace std;

namespace ListTreeUtil {

String::String(std::string value) : value(value){};

bool String::empty() { return value.empty(); }

Char *String::front() { return new Char{value.front()}; }

void String::pop_front() { value.erase(0, 1); };
void String::pop_back() { value.pop_back(); };

void String::clear() { value.clear(); };
String *String::clone() { return new String{value}; };

void String::replaceBy(IList &list) {
  auto another = dynamic_cast<String &>(list);
  value = another.value;
};

bool String::equal(ListTreeUtil::Node *node) {
  auto another = dynamic_cast<String *>(node);
  if (another == nullptr)
    return false;
  return value == another->value;
}

std::string String::to_string() { return value; };

} // namespace ListTreeUtil