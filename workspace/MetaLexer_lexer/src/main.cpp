
#include <CombinatorUtil/include.h>
#include <LexerCombinatorUtil/include.h>
#include <LexerUtil/include.h>
#include <ListTreeUtil/include.h>
#include <ParserCombinatorUtil/include.h>
#include <ParserUtil/include.h>
#include <include_std.h>

using namespace std;
using namespace ListTreeUtil;
using namespace CombinatorUtil;
using namespace LexerCombinatorUtil;
using namespace LexerUtil;
using namespace ParserCombinatorUtil;
using namespace ParserUtil;

struct MatchToken : LexerCombinatorUtil::LexerCombinator {
  ListTreeUtil::Node *lexing(CombinatorUtil::Combinator &root,
                             CombinatorUtil::Combinator &parent,
                             ListTreeUtil::String &text) {
    using LexerCombinatorUtil::Any;
    using LexerCombinatorUtil::Expect;
    return (new Or({new Space, new NextLine, new Bracket, new Comma,
                    new LineComment("//"), new Literal,
                    new And({new Expect("Until"), new Space, new Identifier,
                             new Space, new Identifier}),
                    new Identifier, new Any}))
        ->parsing(root, *this, text);
  }
};

int main() {

  std::string _text =
      "meow42 = Expect \"meow 42\" \n"
      "// struct of aroundMany \n"
      "aroundMany : Combinator before Combinator combinator Combinator after \n"
      "aroundMany = And (before Until combinator after) \n";
  auto text = ListTreeUtil::String(_text);

  auto lexer = new Lexer(new MatchToken());
  auto tree = lexer->lexing(*lexer, *lexer, text);
  tree->print();

  auto list = dynamic_cast<List *>(tree);
  list->recuriveLoop([](ListTreeUtil::Node *node) {
    std::cout << "[" << node->to_string() << "]" << std::endl;
  });

  std::list<std::string> stringList;
  list->recuriveLoop([&stringList](ListTreeUtil::Node *node) {
    auto string = node->to_string();
    if (string.find_first_not_of(" \n") != std::string::npos) {
      stringList.push_back(string);
    }
  });
  for (auto string : stringList) {
    std::cout << "<" << string << ">" << std::endl;
  }

  using ParserCombinatorUtil::Expect;
  using ParserUtil::Identifier;
  using ParserUtil::Literal;

  auto combinator = new Or({

      new And({new Expect("Expect"), new Or({new Identifier, new Literal})}),
      new And({new Expect("")})

  });

  auto structDefine = new And({
      new Identifier,
      new Expect("="),
  });
  auto primary = Many(new Or({}));

  return 0;
}
