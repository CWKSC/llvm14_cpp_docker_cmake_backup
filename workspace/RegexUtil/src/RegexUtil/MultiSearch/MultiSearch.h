#pragma once

#include <include_std.h>

#include "../Structure/include.h"

#include "../GlobalCache/GlobalCache.h"

namespace RegexUtil {

RegexMatchResult
multiRegexSearch(const std::vector<std::string> &regexStringList,
                 const std::string &text);

RegexMatchResult multiRegexSearchWithPriority(
    const std::vector<std::pair<std::string, int>> &regexStringWithPriorityList,
    const std::string &text);

} // namespace RegexUtil