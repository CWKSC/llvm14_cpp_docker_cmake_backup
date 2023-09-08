#include <RegexUtil/include.h>
#include <include_std.h>

#include "../Lexer/Lexer.h"
#include "../Token/include.h"

#include "LexingRule.h"

using namespace std;

namespace LexerUtil {

LexingRule::LexingRule() {}

LexingRule::LexingRule(std::function<DefineLexingFunc()> lexingFunc,
                       int priority)
    : lexingFunc(lexingFunc), priority(priority) {}

/// Common Lexing Function ///

DefineLexingFunc(lexing_ignore) {
  auto length = matchResult.length;
  text.erase(0, length);

  return {};
}

DefineLexingFunc(lexing_keep) {
  auto length = matchResult.length;
  text.erase(0, length);

  return {Token::Base(root, matchResult)};
}

DefineLexingFunc(lexing_nextLine) {
  // std::cout << "lexing_nextLine" << std::endl;

  auto length = matchResult.length;
  text.erase(0, length);

  auto lineCounter = root.getMemory<int>("lineCounter");
  root.setMemory<int>("lineCounter", lineCounter + 1);
  root.setMemory<int>("positionCounter", 0);

  // std::cout << "lexing_nextLine end" << std::endl;
  return {};
}

/// Common Lexing Rule ///
unordered_map<string, LexingRule> commonLexingRules{

    // Space and next line //
    {" +", LexingRule(lexing_ignore, 0)},
    {"\\n", LexingRule(lexing_nextLine, 0)},

    // Word
    {"\\w+", LexingRule(lexing_keep, 0)},

    // Parenthesis //
    {"\\(", LexingRule(lexing_keep, 0)},
    {"\\)", LexingRule(lexing_keep, 0)},

    // Integer and float //
    {"\\d+", LexingRule(lexing_keep, 0)},
    {"[+-]?([0-9]*[.])?[0-9]+", LexingRule(lexing_keep, 1)},

    // Operator
    {"[*+-/]", LexingRule(lexing_keep, 0)},
};

} // namespace LexerUtil