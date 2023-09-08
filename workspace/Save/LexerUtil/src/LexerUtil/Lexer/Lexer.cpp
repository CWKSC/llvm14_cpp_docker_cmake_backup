#include <RegexUtil/include.h>
#include <include_std.h>

#include "../LexingRule/LexingRule.h"
#include "../Token/include.h"

#include "Lexer.h"

using namespace std;
using namespace RegexUtil;

namespace LexerUtil {

Lexer::Lexer() : root(this) {
  setMemory<int>("lineCounter", 0);
  setMemory<int>("positionCounter", 0);
}

Lexer::Lexer(Lexer &lexer)
    : root(lexer.root), lexingRules(lexer.lexingRules), memory(lexer.memory) {}

void Lexer::setRules(unordered_map<string, LexingRule> lexingRules) {
  this->lexingRules = lexingRules;
}

void Lexer::addRule(string regexString, LexingRule lexingRule) {
  lexingRules[regexString] = lexingRule;
}

void Lexer::addRules(unordered_map<string, LexingRule> lexingRules) {
  for (const auto &pair : lexingRules) {
    addRule(pair.first, pair.second);
  }
}

list<Token::Base> Lexer::lexing(string &text) {
  list<Token::Base> result;

  while (!text.empty()) {

    // Lexing Rule to vector<pair<string regexString, int priority>>
    // A parameter pass to RegexUtil::multiRegexSearchWithPriority
    vector<pair<string, int>> searchList;
    for (const auto &pair : lexingRules) {
      searchList.push_back({pair.first, pair.second.priority});
    }

    auto matchResult = multiRegexSearchWithPriority(searchList, text);
    if (!matchResult.isMatch)
      break;

    // std::cout << matchResult << std::endl;

    auto regexString = matchResult.regexString;
    auto position = matchResult.position;
    auto length = matchResult.length;
    auto prefix = matchResult.prefix;
    auto suffix = matchResult.suffix;

    if (prefix != "") {
      std::cout << "[Warning] A prefix exist (" << prefix
                << "), this mean it is not defined" << std::endl;
      auto length = prefix.length();
      result.push_back(Token::Base(*root, prefix));
      auto positionCounter = getMemory<int>("positionCounter");
      setMemory<int>("positionCounter", positionCounter + length);
      text.erase(0, length);
    }

    auto lexingFunc = lexingRules[regexString].lexingFunc;
    auto tokenList = lexingFunc(*root, *this, text, matchResult);

    for (const auto &token : tokenList) {
      result.push_back(token);
    }
  }

  return result;
}

} // namespace LexerUtil