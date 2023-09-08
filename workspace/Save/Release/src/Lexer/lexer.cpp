#include <algorithm>
#include <functional>
#include <iostream>
#include <regex>
#include <string>
#include <unordered_map>
#include <vector>

#include "../Common/RegexMatching/RegexMatching.h"
#include "../Common/Token/BaseToken/BaseToken.h"
#include "PureStruct/LexingResult.h"
#include "PureStruct/LexingRule.h"
#include "PureStruct/LimitCountInfo.h"

LexingResult lexing(std::string text, bool isForward = true,
                    LimitCountInfo limitTimesInfo = LimitCountInfo());
LexingResult lexing_body(std::string text, bool isForward,
                         LimitCountInfo limitTimesInfo);
LexingResult lexing_forward(std::string text, LimitCountInfo limitTimesInfo);
LexingResult lexing_backward(std::string text, LimitCountInfo limitTimesInfo);

int lineCounter = 0;
int positionCounter = 0;

LexingResult lexing_ignore(std::string text, RegexMatchResult matchResult) {
  auto position = positionCounter;
  positionCounter += matchResult.matchString.length();
  return LexingResult({}, matchResult.suffix);
};

LexingResult lexing_keep(std::string text, RegexMatchResult matchResult) {
  auto position = positionCounter;
  positionCounter += matchResult.matchString.length();
  return LexingResult({BaseToken(matchResult.matchString, lineCounter, position,
                                 matchResult.length)},
                      matchResult.suffix);
};

std::function<LexingResult(std::string text, RegexMatchResult matchResult)>
lexing_keep_specific(std::string token) {
  return [token](std::string text, RegexMatchResult matchResult) {
    auto position = positionCounter;
    positionCounter += matchResult.matchString.length();
    return LexingResult(
        {BaseToken(token, lineCounter, position, matchResult.length)},
        matchResult.suffix);
  };
};

std::unordered_map<std::string, LexingRule> lexingRuleTable;
std::vector<std::string> lexingRegexStringList;
std::vector<std::regex> lexingRegexList;

void initLexingRuleTable() {

  lexingRuleTable["\\w+"] = LexingRule("\\w+", lexing_keep);
  lexingRuleTable[" +"] = LexingRule(" +", lexing_ignore);
  lexingRuleTable["\\0"] = LexingRule("\\0", lexing_ignore);
  lexingRuleTable[";"] = LexingRule(";", lexing_keep);
  lexingRuleTable[","] = LexingRule(",", lexing_keep);
  lexingRuleTable["\\("] = LexingRule("\\(", lexing_keep);
  lexingRuleTable["\\)"] = LexingRule("\\)", lexing_keep);
  lexingRuleTable["\\{"] = LexingRule("\\{", lexing_keep);
  lexingRuleTable["\\}"] = LexingRule("\\}", lexing_keep);
  lexingRuleTable["[+-]?([0-9]*[.])?[0-9]+"] =
      LexingRule("[+-]?([0-9]*[.])?[0-9]+", [](std::string text,
                                               RegexMatchResult matchInfo) {
        std::vector<BaseToken> tokenList;
        tokenList.push_back(BaseToken(matchInfo.matchString, lineCounter,
                                      positionCounter, matchInfo.length));
        return LexingResult(tokenList, matchInfo.suffix);
      });

  lexingRuleTable["\\n"] =
      LexingRule("\\n", [](std::string text, RegexMatchResult matchInfo) {
        lineCounter++;
        positionCounter = 0;
        std::cout << "line: " << lineCounter << std::endl;
        return LexingResult({}, matchInfo.suffix);
      });

  lexingRuleTable["//"] =
      LexingRule("//", [](std::string text, RegexMatchResult matchInfo) {
        std::string suffix = matchInfo.suffix;
        auto nextlinePosition = suffix.find("\n");
        lineCounter++;
        positionCounter = 0;
        if (nextlinePosition != std::string::npos) {
          suffix.erase(0, nextlinePosition + 1);
          return LexingResult({}, suffix);
        } else {
          return LexingResult({}, std::string());
        }
      });

  lexingRuleTable["multistring"] = LexingRule(
      "multistring", [](std::string text, RegexMatchResult matchInfo) {
        std::vector<BaseToken> tokenList;
        tokenList.push_back(BaseToken(matchInfo.matchString, lineCounter,
                                      positionCounter, matchInfo.length));

        std::string regexString(
            "multistring *\\{ *\\n([\\s\\S]*?)\\n *\\} *\\n");
        RegexMatchResult regexMatchResult = regexSearch(regexString, text);
        if (!regexMatchResult.isMatch) {
          std::cout << "multistring { } not match" << std::endl;
          throw "multistring { } not match";
        }

        lineCounter++;
        auto captureGroup = regexMatchResult.captureGroups[0];
        auto matchString = captureGroup.matchString;
        tokenList.push_back(BaseToken(captureGroup.matchString, lineCounter,
                                      captureGroup.position,
                                      captureGroup.length));

        lineCounter +=
            std::count(matchString.begin(), matchString.end(), '\n') + 2;
        positionCounter = 0;
        return LexingResult(tokenList, regexMatchResult.suffix);
      });

  lexingRegexStringList.clear();
  for (auto pair : lexingRuleTable) {
    lexingRegexStringList.push_back(pair.first);
  }
  lexingRegexList.clear();
  for (auto pair : lexingRuleTable) {
    lexingRegexList.push_back(pair.second.regex);
  }
}

LexingResult lexing(std::string text, bool isForward,
                    LimitCountInfo limitTimesInfo) {
  std::cout << "[Lexing]" << std::endl;
  initLexingRuleTable();
  return lexing_body(text, isForward, limitTimesInfo);
}

LexingResult lexing_body(std::string text, bool isForward,
                         LimitCountInfo limitTimesInfo) {

  std::vector<BaseToken> tokenList;
  int regexSearchCount = 0;

  while (true) {

    RegexMatchResult regexMatchInfo =
        multiRegexSearch(lexingRegexStringList, text, isForward);
    if (!regexMatchInfo.isMatch)
      break;

    auto regexString = regexMatchInfo.regexString;
    auto position = regexMatchInfo.position;
    auto length = regexMatchInfo.length;
    auto prefix = regexMatchInfo.prefix;
    auto suffix = regexMatchInfo.suffix;

    std::cout << "regexString: " << regexString
              << ", matchString: " << regexMatchInfo.matchString
              << ", prefix: " << prefix << ", line: " << lineCounter
              << ", length: " << length << ", position: " << position
              << std::endl;

    if (prefix != "") {
      tokenList.push_back(BaseToken(prefix, lineCounter, position, length));
      positionCounter += prefix.length();
    }
    auto lexingFunc = lexingRuleTable[regexString].lexingFunc;
    auto lexingResult = lexingFunc(text, regexMatchInfo);

    for (int i = 0; i < lexingResult.tokenList.size(); i++) {
      tokenList.push_back(lexingResult.tokenList[i]);
    }
    text = lexingResult.remainText;

    bool isTokenCountReachLimit = false;
    if (limitTimesInfo.tokenCount != -1) {
      if (tokenList.size() >= limitTimesInfo.tokenCount) {
        isTokenCountReachLimit = true;
        std::cout << "reach limit" << std::endl;
      }
    }

    bool isRegexSearchCountLimit = false;
    regexSearchCount++;
    if (limitTimesInfo.regexSearchCount != -1) {
      if (limitTimesInfo.regexSearchCount == regexSearchCount) {
        isRegexSearchCountLimit = true;
      }
    }

    if (limitTimesInfo.isMinMode) {
      if (isTokenCountReachLimit || isRegexSearchCountLimit) {
        break;
      }
    } else {
      if (isTokenCountReachLimit && isRegexSearchCountLimit) {
        break;
      }
    }
  }

  return LexingResult(tokenList, text);
}

LexingResult lexing_forward(std::string text, LimitCountInfo limitTimesInfo) {
  return lexing_body(text, true, limitTimesInfo);
}

LexingResult lexing_backward(std::string text, LimitCountInfo limitTimesInfo) {
  return lexing_body(text, false, limitTimesInfo);
}
