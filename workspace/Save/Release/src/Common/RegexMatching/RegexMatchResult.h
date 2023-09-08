#pragma once

#include <regex>
#include <string>
#include <vector>

#include "CaptureGroup.h"

struct RegexMatchResult {
  std::string regexString;

  std::string matchString;
  int position;
  int length;

  std::vector<CaptureGroup> captureGroups;
  std::string prefix;
  std::string suffix;
  bool isMatch;
};
