#include <CombinatorUtil/include.h>
#include <ListTreeUtil/include.h>
#include <include_std.h>

#include "../../LexerCombinator/LexerCombinator.h"

#include "Any.h"

using namespace std;

namespace LexerCombinatorUtil {

ListTreeUtil::String *Any::lexing(CombinatorUtil::Combinator &root,
                                  CombinatorUtil::Combinator &parent,
                                  ListTreeUtil::String &text) {
  if (text.empty()) {
    std::cout << "expect Any, but text is empty" << std::endl;
    return nullptr;
  }
  auto front = text.front();
  text.pop_front();
  return new ListTreeUtil::String(std::string{front->value});
}

} // namespace LexerCombinatorUtil
