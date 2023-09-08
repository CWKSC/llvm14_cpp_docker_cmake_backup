
#include "../../../Expect/Expect.h"
#include "../../../LexerCombinator/LexerCombinator.h"
#include "../../../Or_/Or_.h"

#include "../Float/Float.h"
#include "../Integer/Integer.h"
#include "../String_/String_.h"

#include "Literal.h"

namespace LexerCombinatorUtil {

Token::Base *Literal::parsing(LexerCombinator &root, LexerCombinator &parent,
                              std::string &text) {
  return (new Or({new Float, new Integer, new String}))
      ->parsing(root, *this, text);
}

} // namespace LexerCombinatorUtil