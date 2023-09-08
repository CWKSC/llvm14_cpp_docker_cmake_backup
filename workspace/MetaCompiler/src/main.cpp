
#include <ParserCombinatorUtil/include.h>
#include <include_std.h>

using namespace std;
using namespace ParserCombinatorUtil;

struct Bracket : ParserCombinator {
  AST::Sequence *parsing(ParserCombinator &root, ParserCombinator &parent,
                         std::list<std::string> &tokenList) {
    return (new AroundMany(new Expect("("), &root, new Expect(")")))
        ->parsing(root, *this, tokenList);
  }
};

void test_bracket_matching() {
  std::list<std::string> tokenList = {"(", "(", ")", "(", "(",
                                      ")", "(", ")", ")", ")"};
  auto primary = Bracket();
  auto ast = primary.parsing(primary, primary, tokenList);
  ast->println();
}

void test_func_with_optional() {
  std::list<std::string> tokenList = {"func", "meow", "("};
  std::list<std::string> tokenList2 = {"func", "("};

  auto primary = And(
      {new Expect("func"), new Optional(new Expect("meow")), new Expect("(")});
  auto ast = primary.parsing(primary, primary, tokenList);
  ast->println();

  ast = primary.parsing(primary, primary, tokenList2);
  ast->println();
}

int main() {
  test_bracket_matching();
  test_func_with_optional();
  return 0;
}
