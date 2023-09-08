#pragma once

#include <RegexUtil/include.h>
#include <include_std.h>

#include "../Token/include.h"

namespace LexerUtil {
struct Lexer;

#define DefineLexingFunc(name)                                                 \
  std::list<Token::Base> name(Lexer &root, Lexer &lexer, std::string &text,    \
                              RegexUtil::RegexMatchResult &matchResult)

struct LexingRule {
  std::function<DefineLexingFunc()> lexingFunc;
  int priority;
  LexingRule();
  LexingRule(std::function<DefineLexingFunc()> lexingFunc, int priority);
};

// Common Lexing Function //
DefineLexingFunc(lexing_ignore);
DefineLexingFunc(lexing_keep);
DefineLexingFunc(lexing_nextLine);

// Common Lexing Rules
extern std::unordered_map<std::string, LexingRule> commonLexingRules;

} // namespace LexerUtil