
#include <include_std.h>

#include "RegexMatchResult.h"

using namespace std;

namespace RegexUtil {

ostream &operator<<(ostream &os, const RegexMatchResult &result) {

  os << "regexString: " << result.regexString << '\n';

  if (!result.isMatch) {
    os << "isMatch: false" << endl;
    return os;
  }

  os << "matchString: " << result.matchString << '\n';
  os << "position: " << result.position << '\n';
  os << "length: " << result.length << '\n';
  os << "prefix: " << result.prefix << '\n';
  os << "suffix: " << result.suffix << endl;
  for (int i = 0; i < result.captureGroups.size(); i++) {
    auto &captureGroup = result.captureGroups[i];
    os << "captureGroups[" << i << "]" << '\n';
    os << captureGroup;
  }

  return os;
}

} // namespace RegexUtil