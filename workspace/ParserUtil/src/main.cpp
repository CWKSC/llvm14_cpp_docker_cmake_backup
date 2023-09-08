
#include <CombinatorUtil/include.h>
#include <ListTreeUtil/include.h>
#include <ParserCombinatorUtil/include.h>
#include <include_std.h>

#include "ParserUtil/include.h"

using namespace std;
using namespace ListTreeUtil;
using namespace CombinatorUtil;
using namespace ParserCombinatorUtil;
using namespace ParserUtil;

int main() {
  using ParserCombinatorUtil::Expect;

  std::list<std::string> _list{
      "meow42",      "=",          "Expect",
      "\"meow 42\"", "//",         "struct of aroundMany \n",
      "aroundMany",  ":",          "Combinator",
      "before",      "Combinator", "combinator",
      "Combinator",  "after",      ";",
      "aroundMany",  "=",          "And",
      "(",           "before",     "Until",
      "combinator",  "after",      ")"};

  auto list = StringList(_list);

  Or *combinator;

  auto bracketGroup =
      new And({new Expect("("),
               new UntilPeek(new Or({new Ref((Combinator **)&combinator),
                                     new Identifier}),
                             new Expect(")"))});

  combinator = new Or({

      new And({new Expect("Expect"), new Or({new Identifier, new Literal})}),
      new And({new Expect("And"), bracketGroup}),
      new And({new Expect("Until"), new Identifier, new Identifier}),

  });

  auto typeName = new And({new Identifier, new Identifier});
  auto structDefine = new And({new Identifier, new Expect(":"),
                               new UntilPeek(typeName, new Expect(";"))});

  auto combinatorDefine =
      new And({new Identifier, new Expect("="), combinator});

  auto primary =
      Many(new Or({structDefine, combinatorDefine, new LineComment("//")}));
  auto tree = primary.parsing(primary, primary, list);
  tree->println();

  return 0;
}
