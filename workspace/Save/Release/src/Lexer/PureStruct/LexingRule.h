#pragma once

#include <functional>
#include <regex>
#include <string>
#include <vector>

#include "../../Common/RegexMatching/RegexMatching.h"
#include "../../Common/Token/BaseToken/BaseToken.h"
#include "LexingResult.h"

struct LexingRule {

  std::string regexString;
  std::regex regex;
  std::function<LexingResult(std::string text, RegexMatchResult matchResult)>
      lexingFunc;

  LexingRule() {}
  LexingRule(std::string _regexString,
             std::function<LexingResult(std::string text,
                                        RegexMatchResult matchResult)>
                 _lexingFunc) {
    regexString = _regexString;
    regex = std::regex(_regexString);
    lexingFunc = _lexingFunc;
  }
};
