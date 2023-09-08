
#include <include_std.h>

#include "ListTreeUtil/include.h"

using namespace std;
using namespace ListTreeUtil;

List *stringToList(std::string value) {
  auto list = new List;
  for (auto c : value) {
    list->push_back(new Char{c});
  }
  return list;
}

int main() {

  auto _char = 'm';
  auto char_ = Char(_char);
  char_.println();

  auto _string = "meow";
  auto string = String(_string);
  string.println();

  auto stringList = StringList({"41", "42", "43"});
  stringList.println();

  List list;
  list.push_back(new String("a"));
  list.push_back(new StringList({"b", "c", "d"}));
  list.push_back(new List({new String("e"), new String("f"),
                           new List({new String("g"), new String("h")})}));
  list.println();

  return 0;
}
