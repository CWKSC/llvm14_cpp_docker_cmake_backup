#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "../Common/RegexMatching/RegexMatching.h"
#include "../Common/Token/BaseToken/BaseToken.h"
#include "../Common/Token/TaggedToken/TaggedToken.h"
#include "PureStruct/TaggingResult.h"
#include "PureStruct/TaggingRule.h"

TaggingResult tagging(const std::vector<BaseToken> &tokenList);
void initTagging();
TaggingResult tagging_body(const std::vector<BaseToken> &tokenList);

std::unordered_map<std::string, TaggingRule> taggingRuleTable;

TaggingResult tagging(const std::vector<BaseToken> &tokenList) {
  std::cout << "[Tagging]" << std::endl;
  initTagging();
  return tagging_body(tokenList);
}

void initTagging() {
  taggingRuleTable["\\w+"] = TaggingRule(
      [](std::string, RegexMatchResult matchResult) { return "text"; });
  taggingRuleTable["\\("] = TaggingRule(
      [](std::string, RegexMatchResult matchResult) { return "("; });
  taggingRuleTable["\\)"] = TaggingRule(
      [](std::string, RegexMatchResult matchResult) { return ")"; });
  taggingRuleTable["[+-]?([0-9]*[.])?[0-9]+"] = TaggingRule(
      [](std::string, RegexMatchResult matchResult) { return "float"; });
  taggingRuleTable["\\d+"] = TaggingRule(
      [](std::string, RegexMatchResult matchResult) { return "integer"; });
  taggingRuleTable["main"] = TaggingRule(
      [](std::string, RegexMatchResult matchResult) { return "main"; });
  taggingRuleTable["func"] = TaggingRule(
      [](std::string, RegexMatchResult matchResult) { return "func"; });
  taggingRuleTable["extern"] = TaggingRule(
      [](std::string, RegexMatchResult matchResult) { return "extern"; });
  taggingRuleTable["[+*-<]"] =
      TaggingRule([](std::string, RegexMatchResult matchResult) {
        return "binary operator";
      });
  taggingRuleTable["if"] = TaggingRule(
      [](std::string, RegexMatchResult matchResult) { return "if"; });
  taggingRuleTable["else"] = TaggingRule(
      [](std::string, RegexMatchResult matchResult) { return "else"; });
  taggingRuleTable["for"] = TaggingRule(
      [](std::string, RegexMatchResult matchResult) { return "for"; });
  taggingRuleTable[";"] = TaggingRule(
      [](std::string, RegexMatchResult matchResult) { return ";"; });
}

std::string matchTag(const BaseToken &baseToken) {
  for (const auto &pair : taggingRuleTable) {
    auto text = baseToken.string;
    auto regexMatchResult = regexMatch(pair.first, text);
    if (!regexMatchResult.isMatch)
      continue;
    auto regexString = regexMatchResult.regexString;
    auto taggingFunc = taggingRuleTable[regexString].taggingFunc;
    return taggingFunc(text, regexMatchResult);
  }
  return "not-match-any-tag";
}

TaggingResult tagging_body(const std::vector<BaseToken> &tokenList) {
  TaggingResult taggingResult;

  std::vector<TaggedToken> taggedTokenList;
  for (const BaseToken &baseToken : tokenList) {
    std::string tag = matchTag(baseToken);
    taggedTokenList.push_back(TaggedToken(tag, baseToken));
  }

  taggingResult.taggedTokenList = taggedTokenList;
  return taggingResult;
}
