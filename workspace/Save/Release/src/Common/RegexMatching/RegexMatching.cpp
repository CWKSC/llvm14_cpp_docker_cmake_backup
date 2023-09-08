
#include <iostream>
#include <regex>
#include <string>
#include <vector>

#include "RegexMatchResult.h"

RegexMatchResult regexSearchOrMatch(bool isSearch,
                                    const std::string &regexString,
                                    const std::string &text, bool isForward) {

  RegexMatchResult regexMatchResult;
  std::smatch matchInfo;

  if (isSearch) {
    if (!std::regex_search(text, matchInfo, std::regex(regexString))) {
      regexMatchResult.isMatch = false;
      return regexMatchResult;
    }
  } else {
    if (!std::regex_match(text, matchInfo, std::regex(regexString))) {
      regexMatchResult.isMatch = false;
      return regexMatchResult;
    }
  }

  int index = isForward ? 0 : (matchInfo.size() - 1);
  int capturingGroupSize = matchInfo.size();

  regexMatchResult.regexString = regexString;
  regexMatchResult.matchString = matchInfo.str();
  regexMatchResult.position = matchInfo.position();
  regexMatchResult.length = matchInfo.length();

  for (int i = 1; i < capturingGroupSize; i++) {
    regexMatchResult.captureGroups.push_back(CaptureGroup(
        matchInfo.str(i), matchInfo.length(i), matchInfo.position(i)));
  }

  regexMatchResult.prefix = matchInfo.prefix();
  regexMatchResult.suffix = matchInfo.suffix();
  regexMatchResult.isMatch = true;

  return regexMatchResult;
}

RegexMatchResult regexMatch(const std::string &regexString,
                            const std::string &text, bool isForward) {
  return regexSearchOrMatch(false, regexString, text, isForward);
}

RegexMatchResult regexSearch(const std::string &regexString,
                             const std::string &text, bool isForward) {
  return regexSearchOrMatch(true, regexString, text, isForward);
}

RegexMatchResult
multiRegexSearch(const std::vector<std::string> &regexStringList,
                 const std::string &text, bool isForward) {

  RegexMatchResult regexMatchResult;
  RegexMatchResult minRegexMatchResult;
  auto minDistance = INT32_MAX;
  bool anyMatch = false;

  for (auto &regexString : regexStringList) {
    auto regexMatchResult = regexSearch(regexString, text, isForward);
    if (!regexMatchResult.isMatch)
      continue;

    anyMatch = true;
    int position = regexMatchResult.position;
    if (position < minDistance) {
      minDistance = position;
      minRegexMatchResult = regexMatchResult;
    }
  }

  if (!anyMatch) {
    minRegexMatchResult.isMatch = false;
    return minRegexMatchResult;
  }

  return minRegexMatchResult;
}
