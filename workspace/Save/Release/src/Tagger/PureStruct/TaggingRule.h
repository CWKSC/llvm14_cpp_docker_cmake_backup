
#pragma once

#include "TaggingResult.h"

struct TaggingRule {

  std::function<std::string(std::string, RegexMatchResult matchResult)>
      taggingFunc;

  TaggingRule() {}
  TaggingRule(
      std::function<std::string(std::string text, RegexMatchResult matchResult)>
          _teggingFunc) {
    taggingFunc = _teggingFunc;
  }
};
