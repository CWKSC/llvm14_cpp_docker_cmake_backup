
#include <include_std.h>

#include "CaptureGroup.h"

using namespace std;

namespace RegexUtil {

ostream &operator<<(ostream &os, const CaptureGroup &result) {
  os << "matchString: " << result.matchString << '\n';
  os << "length: " << result.length << '\n';
  os << "position: " << result.position << endl;
  return os;
}

} // namespace RegexUtil