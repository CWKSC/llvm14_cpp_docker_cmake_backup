
#include <CombinatorUtil/include.h>
#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "ParserCombinatorUtil/include.h"

using namespace std;
using namespace ListTreeUtil;
using namespace CombinatorUtil;
using namespace ParserCombinatorUtil;

struct Bracket : ParserCombinatorUtil::ParserCombinator {
  ListTreeUtil::Node *parsing(CombinatorUtil::Combinator &root,
                              CombinatorUtil::Combinator &parent,
                              ListTreeUtil::StringList &list) override {
    using ParserCombinatorUtil::Expect;
    return (new AroundMany(new Expect("("), &root, new Expect(")")))
        ->parsing(root, *this, list);
  }
};

void test_bracket_matching() {
  using ParserCombinatorUtil::Expect;
  std::list<std::string> _list = {"(", "(", ")", "(", "(",
                                  ")", "(", ")", ")", ")"};
  auto list = ListTreeUtil::StringList(_list);
  auto primary = Bracket();
  auto tree = primary.parsing(primary, primary, list);
  tree->println();
}

void test_func_with_optional() {
  using ParserCombinatorUtil::Expect;

  auto primary = And(
      {new Expect("func"), new Optional(new Expect("meow")), new Expect("(")});

  std::list<std::string> _list = {"func", "meow", "("};
  auto list = ListTreeUtil::StringList(_list);
  auto tree = primary.parsing(primary, primary, list);
  tree->println();

  _list = {"func", "("};
  list = ListTreeUtil::StringList(_list);
  tree = primary.parsing(primary, primary, list);
  tree->println();
}

int main() {
  test_bracket_matching();
  test_func_with_optional();
  return 0;
}
