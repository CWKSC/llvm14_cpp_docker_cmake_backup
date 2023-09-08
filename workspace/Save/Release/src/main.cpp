#include <iostream>
#include <string>

#include <regex>

#include "CodeGenerator/CodeGenerator.h"
#include "IRToObjectFileConverter/IRToObjectFileConverter.h"
#include "Lexer/lexer.h"
#include "Parser/parser.h"
#include "Tagger/tagger.h"

int main() {

  // std::string text = "int main() {\n"
  //                    "    // it is comment\n"
  //                    "    foo(a, b);\n"
  //                    "    multistring {\n"
  //                    "        aasdbsahd sa dhsab djsab jdh\n"
  //                    "         asjdiojas dsa {{ meow }} djisajod sai d }\n"
  //                    "        dasdsa das djsaio djas \n"
  //                    "    }\n"
  //                    "    return 42;\n"
  //                    "}\n";

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
                     "    * 4.0 (+ 3.0 (- 3.0 4.0))\n"
                     ")\n";

  // std::string text = "main (\n"
  //                    "    multistring {\n"
  //                    "        aasdbsahd sa dhsab djsab jdh\n"
  //                    "         asjdiojas dsa {{ meow }} djisajod sai d }\n"
  //                    "        dasdsa das djsaio djas \n"
  //                    "    }\n"
  //                    "    sin 3.0\n"
  //                    ")\n";

  // std::string text = "extern sin(x)\n"
  //                    "extern putchard(char)\n"
  //                    "func foo(a) (\n"
  //                    "    sin a\n"
  //                    ")\n"
  //                    "main (\n"
  //                    "    sin 3.0\n"
  //                    ")\n";

  // Lexing //
  auto lexingResult = lexing(text);
  auto tokenList = lexingResult.tokenList;
  for (const auto &baseToken : tokenList) {
    std::cout << baseToken << std::endl;
  }
  std::cout << std::endl;

  // Tagging //
  auto taggingResult = tagging(tokenList);
  auto taggedTokenList = taggingResult.taggedTokenList;
  for (const auto &taggedToken : taggedTokenList) {
    std::cout << taggedToken << std::endl;
  }
  std::cout << std::endl;

  // Parsing //
  Parser parser;
  auto parsingResult = parser.parsing(taggedTokenList);
  auto root = parsingResult.root;
  root->printInside(std::cout, 0);
  std::cout << std::endl;

  // Code generation //
  CodeGenerator codeGenerator;
  codeGenerator.codeGenerating(root);
  std::cout << std::endl;

  // IR to Object File //
  IRToObjectFileConverter irToObjectFileConverter;
  irToObjectFileConverter.converting(&codeGenerator);
  std::cout << std::endl;

  return 0;
}
