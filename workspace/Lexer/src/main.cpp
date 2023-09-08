
#include <LexerCombinatorUtil/include.h>
#include <include_std.h>

#include "LexerUtil/include.h"

using namespace std;
using namespace LexerCombinatorUtil;
using namespace LexerUtil;

int main() {

  std::string text = "extern sin(x)\n"
                     "extern putchard(char)\n"
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
  auto lexer = new Lexer();

  auto tree = lexer->parsing(*lexer, *lexer, text);
  tree->print();

  return 0;
}
