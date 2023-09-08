#include <include_std.h>

#include "../../IList/IList.h"
#include "../../Node/Node.h"

#include "../String_/String_.h"

#include "StringList.h"

using namespace std;

namespace ListTreeUtil {

StringList::StringList(std::list<std::string> value) : value(value){};

bool StringList::empty() { return value.empty(); }

String *StringList::front() { return new String(value.front()); }

void StringList::pop_front() { value.pop_front(); };
void StringList::pop_back() { value.pop_back(); };

void StringList::clear() { value.clear(); };
StringList *StringList::clone() { return new StringList{value}; };

void StringList::replaceBy(IList &list) {
  auto another = dynamic_cast<StringList &>(list);
  value = another.value;
};

bool StringList::equal(Node *node) {
  auto another = dynamic_cast<StringList *>(node);
  if (another == nullptr)
    return false;
  return value == another->value;
}

std::string StringList::to_string() {
  std::string result;
  for (auto &v : value) {
    result += v;
  }
  return result;
};

} // namespace ListTreeUtil