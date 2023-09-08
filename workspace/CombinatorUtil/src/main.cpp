
#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "CombinatorUtil/include.h"

using namespace CombinatorUtil;
using namespace std;
using namespace ListTreeUtil;

int main() {

  auto list = ListTreeUtil::List{};
  list.push_back(new String{"meow"});
  list.push_back(new Char{'4'});
  list.push_back(new Char{'2'});
  auto combinator = new UntilPeek(new Any, new Expect(new Char('2')));
  auto result = combinator->parsing(*combinator, *combinator, list);
  result->println();

  return 0;
}
