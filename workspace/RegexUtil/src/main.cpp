#include <include_std.h>

#include "RegexUtil/include.h"

using namespace std;
using namespace RegexUtil;

int main() {

  auto text = "-12.34";

  vector<pair<string, int>> rules{{"[+-]?([0-9]*[.])?[0-9]+", 1},
                                  {"[+-]?\\d+", 0}};

  auto result = multiRegexSearchWithPriority(rules, text);
  std::cout << result << std::endl;

  return 0;
}
