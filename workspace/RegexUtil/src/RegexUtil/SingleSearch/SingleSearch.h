#pragma once

#include <include_std.h>

#include "../Structure/include.h"

#include "../GlobalCache/GlobalCache.h"

namespace RegexUtil {

RegexMatchResult regexMatch(const std::string &regexString,
                            const std::string &text);
RegexMatchResult regexSearch(const std::string &regexString,
                             const std::string &text);

RegexMatchResult regexSearchInFront(const std::string &regexString,
                                    const std::string &text);

} // namespace RegexUtil
