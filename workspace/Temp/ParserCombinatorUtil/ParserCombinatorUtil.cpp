
#include <include_std.h>

#include "../AST/Base/Base.h"
#include "../AST/Sequence/Sequence.h"
#include "../Parser/forward.h"

#include "ParserCombinatorUtil.h"

using namespace std;
using namespace ParserUtil::AST;

namespace ParserUtil::ParserCombinatorUtil {

DefineParserCombinator_listAsInput(and_) {
  Sequence *sequence = new Sequence;
  for (const auto &func : parsingFuncList) {
    auto ast = func(root, parser, tokenList);
    if (ast != nullptr) {
      sequence->add(ast);
    } else {
      return (Sequence *)nullptr;
    }
  }
  return sequence;
}
DefineParserCombinator_end

DefineParserCombinator_listAsInput(or_) {
  for (const auto &func : parsingFuncList) {
    auto cloneTokenList = list<string>(tokenList);
    auto ast = func(root, parser, cloneTokenList);
    if (ast != nullptr) {
      tokenList.clear();
      tokenList.insert(tokenList.end(), cloneTokenList.begin(),
                       cloneTokenList.end());
      return ast;
    }
  }
  return (Base *)nullptr;
}
DefineParserCombinator_end

DefineParserCombinator_funcAsInput(option) {
  auto ast = parsingFunc(root, parser, tokenList);
  if (ast == nullptr) {
    return (Base *)nullptr;
  }
  return ast;
}
DefineParserCombinator_end

DefineParserCombinator_funcAsInput(many) {
  Sequence *sequence = new Sequence;
  while (true) {
    auto ast = parsingFunc(root, parser, tokenList);
    if (ast == nullptr) {
      return sequence;
    }
    sequence->add(ast);
  }
}
DefineParserCombinator_end

DefineParserCombinator_funcAsInput(atLeastOne) {
  Sequence *sequence = new Sequence;
  auto ast = parsingFunc(root, parser, tokenList);
  if (ast == nullptr) {
    return (Sequence *)nullptr;
  }
  auto astList = many(parsingFunc)(root, parser, tokenList);
  sequence->add(astList);
  return sequence;
}
DefineParserCombinator_end

} // namespace ParserUtil::ParserCombinatorUtil
