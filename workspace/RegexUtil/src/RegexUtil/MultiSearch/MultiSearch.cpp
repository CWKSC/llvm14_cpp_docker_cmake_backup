
#include <include_std.h>

#include "../GlobalCache/GlobalCache.h"
#include "../SingleSearch/SingleSearch.h"
#include "../Structure/include.h"

using namespace std;

namespace RegexUtil {

RegexMatchResult multiRegexSearch(const vector<string> &regexStringList,
                                  const string &text) {

  RegexMatchResult minResult;
  auto minDistance = INT32_MAX;
  bool anyMatch = false;

  for (const auto &regexString : regexStringList) {
    auto result = regexSearch(regexString, text);
    if (!result.isMatch)
      continue;

    anyMatch = true;
    int position = result.position;
    if (position < minDistance) {
      minDistance = position;
      minResult = result;
    }
  }

  if (!anyMatch) {
    minResult.isMatch = false;
    return minResult;
  }

  return minResult;
}

RegexMatchResult multiRegexSearchWithPriority(
    const vector<pair<string, int>> &regexStringWithPriorityList,
    const string &text) {

  RegexMatchResult minResult;
  auto minDistance = INT32_MAX;
  auto minResultPriority = -1;
  bool anyMatch = false;

  for (const auto &regexStringWithPriority : regexStringWithPriorityList) {
    auto regexString = regexStringWithPriority.first;
    auto priority = regexStringWithPriority.second;
    auto result = regexSearch(regexString, text);
    if (!result.isMatch)
      continue;

    anyMatch = true;
    int position = result.position;
    if (position < minDistance) {
      minDistance = position;
      minResultPriority = priority;
      minResult = result;
    } else if (position == minDistance) {
      if (priority > minResultPriority) {
        minDistance = position;
        minResultPriority = priority;
        minResult = result;
      }
    }
  }

  if (!anyMatch) {
    minResult.isMatch = false;
    return minResult;
  }

  return minResult;
}

} // namespace RegexUtil