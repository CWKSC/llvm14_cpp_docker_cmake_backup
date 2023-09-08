
#include <CombinatorUtil/include.h>
#include <LexerCombinatorUtil/include.h>
#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "LexerUtil/include.h"

using namespace std;
using namespace ListTreeUtil;
using namespace CombinatorUtil;
using namespace LexerCombinatorUtil;
using namespace LexerUtil;

struct MatchToken : LexerCombinatorUtil::LexerCombinator {
  ListTreeUtil::Node *lexing(CombinatorUtil::Combinator &root,
                             CombinatorUtil::Combinator &parent,
                             ListTreeUtil::String &text) {
    return (new Or({new Space, new NextLine, new Bracket, new Comma,
                    new LineComment("//"), new Literal, new Identifier,
                    new LexerCombinatorUtil::Any}))
        ->parsing(root, *this, text);
  }
};

int main() {

  std::string _text = "extern sin(x)\n"
                      "extern putchard(char)\n"
                      "// it is comment \n"
                      "func foo(a) (\n"
                      "    sin a\n"
                      ")\n"
                      "main (\n"
                      "    if 1 (\n"
                      "        putchard 42\n"
                      "    ) else (\n"
                      "        putchard 43\n"
                      "    )\n"
                      "    for i 1 5 1 (\n"
                      "        putchard 42\n"
                      "    )\n"
                      "    * 4.0 (+ 3.0 (- 3.0 -4.0))\n"
                      ")\n";
  auto text = ListTreeUtil::String(_text);

  auto lexer = new Lexer(new MatchToken());
  auto tree = lexer->lexing(*lexer, *lexer, text);
  tree->print();

  auto list = dynamic_cast<List *>(tree);
  list->recuriveLoop([](ListTreeUtil::Node *node) {
    std::cout << "[" << node->to_string() << "]" << std::endl;
  });

  return 0;
}
