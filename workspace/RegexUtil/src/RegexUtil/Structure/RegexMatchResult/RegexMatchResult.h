#pragma once

#include <include_std.h>

#include "../CaptureGroup/CaptureGroup.h"

namespace RegexUtil {

struct RegexMatchResult {
  std::string regexString;

  std::string matchString;
  int position;
  int length;

  std::vector<CaptureGroup> captureGroups;
  std::string prefix;
  std::string suffix;
  bool isMatch;

  friend std::ostream &operator<<(std::ostream &os,
                                  const RegexMatchResult &result);
};

} // namespace RegexUtil
