#include <CombinatorUtil/include.h>
#include <LexerCombinatorUtil/include.h>
#include <ListTreeUtil/include.h>

#include "Lexer.h"

using namespace CombinatorUtil;
using namespace LexerCombinatorUtil;

namespace LexerUtil {

Lexer::Lexer(LexerCombinatorUtil::LexerCombinator *matchToken)
    : matchToken(matchToken) {}

ListTreeUtil::Node *Lexer::lexing(CombinatorUtil::Combinator &root,
                                  CombinatorUtil::Combinator &parent,
                                  ListTreeUtil::String &text) {
  return (new Many(matchToken))->parsing(root, *this, text);
}

} // namespace LexerUtil