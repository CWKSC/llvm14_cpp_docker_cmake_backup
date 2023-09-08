
#include <include_std.h>

#include "../Structure/include.h"

#include "../GlobalCache/GlobalCache.h"

using namespace std;

namespace RegexUtil {

RegexMatchResult regexSearchOrMatch(const string &regexString,
                                    const string &text, bool isSearch) {

  RegexMatchResult result;
  smatch matchInfo;
  regex regexp;

  // Get from regexCache //
  if (regexCache.count(regexString)) {
    regexp = regexCache[regexString];
  } else {
    regexp = regex(regexString);
    regexCache[regexString] = regexp;
  }

  if (isSearch) {
    if (!regex_search(text, matchInfo, std::regex(regexString))) {
      result.isMatch = false;
      return result;
    }
  } else {
    if (!regex_match(text, matchInfo, std::regex(regexString))) {
      result.isMatch = false;
      return result;
    }
  }

  result.regexString = regexString;
  result.matchString = matchInfo.str();
  result.position = matchInfo.position();
  result.length = matchInfo.length();

  int capturingGroupSize = matchInfo.size();
  for (int i = 1; i < capturingGroupSize; i++) {
    auto matchString = matchInfo.str(i);
    auto position = matchInfo.position(i);
    auto length = matchInfo.length(i);
    result.captureGroups.push_back(CaptureGroup(matchString, position, length));
  }

  result.prefix = matchInfo.prefix();
  result.suffix = matchInfo.suffix();
  result.isMatch = true;

  return result;
}

RegexMatchResult regexMatch(const string &regexString, const string &text) {
  return regexSearchOrMatch(regexString, text, false);
}

RegexMatchResult regexSearch(const string &regexString, const string &text) {
  return regexSearchOrMatch(regexString, text, true);
}

RegexMatchResult regexSearchInFront(const string &regexString,
                                    const string &text) {
  auto result = regexSearchOrMatch(regexString, text, true);
  if (!result.isMatch)
    return result;
  if (result.position != 0) {
    result.isMatch = false;
    return result;
  }
  return result;
}

} // namespace RegexUtil