
#include "../../Expect/Expect.h"
#include "../../LexerCombinator/LexerCombinator.h"
#include "../../Or_/Or_.h"

#include "Bracket.h"

namespace LexerCombinatorUtil {

Token::Base *Bracket::parsing(LexerCombinator &root, LexerCombinator &parent,
                              std::string &text) {
  return (new Or({
              new Expect("("),
              new Expect(")"),
              new Expect("{"),
              new Expect("}"),
              new Expect("["),
              new Expect("]"),
          }))
      ->parsing(root, *this, text);
}

} // namespace LexerCombinatorUtil