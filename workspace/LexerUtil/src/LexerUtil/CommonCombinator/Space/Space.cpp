#include <CombinatorUtil/include.h>
#include <LexerCombinatorUtil/include.h>
#include <include_std.h>

#include "../../Node/Space/Space.h"

#include "Space.h"

using namespace CombinatorUtil;
using namespace LexerCombinatorUtil;

namespace LexerUtil {
using LexerCombinatorUtil::Expect;

ListTreeUtil::Node *Space::lexing(CombinatorUtil::Combinator &root,
                                  CombinatorUtil::Combinator &parent,
                                  ListTreeUtil::String &text) {
  auto pureToken = (new RegexExpect(" +"))->lexing(root, *this, text);
  if (pureToken == nullptr)
    return nullptr;
  return new Node::Space(pureToken->value);
}

} // namespace LexerUtil
