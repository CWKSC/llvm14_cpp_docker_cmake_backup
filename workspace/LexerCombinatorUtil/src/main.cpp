
#include <CombinatorUtil/include.h>
#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "LexerCombinatorUtil/include.h"

using namespace std;
using namespace LexerCombinatorUtil;
using namespace ListTreeUtil;
using namespace CombinatorUtil;

int main() {
  using LexerCombinatorUtil::Expect;

  auto text = String{"meow      endremain"};
  auto primary =
      new And({new Expect("meow"), new RegexExpect(" +"), new Expect("end")});

  auto tree = primary->parsing(*primary, *primary, text);
  tree->println();
  text.println();

  return 0;
}
