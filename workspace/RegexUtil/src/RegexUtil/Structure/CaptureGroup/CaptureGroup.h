#pragma once

#include <include_std.h>

namespace RegexUtil {

struct CaptureGroup {

  std::string matchString;
  int position;
  int length;

  CaptureGroup(std::string matchString, int position, int length)
      : matchString(matchString), position(position), length(length) {}
  friend std::ostream &operator<<(std::ostream &os, const CaptureGroup &result);
};

} // namespace RegexUtil
