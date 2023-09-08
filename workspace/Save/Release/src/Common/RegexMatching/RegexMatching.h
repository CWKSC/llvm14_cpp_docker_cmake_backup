#pragma once

#include <string>
#include <vector>

#include "RegexMatchResult.h"

RegexMatchResult regexMatch(const std::string &regexString,
                            const std::string &text, bool isForward = true);
RegexMatchResult regexSearch(const std::string &regexString,
                             const std::string &text, bool isForward = true);

RegexMatchResult
multiRegexSearch(const std::vector<std::string> &regexStringList,
                 const std::string &text, bool isForward = true);
