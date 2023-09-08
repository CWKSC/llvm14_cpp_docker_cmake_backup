#include <gtest/gtest.h>

#include "SingleSearch.h"

using namespace RegexUtil;

TEST(RegexSearchInFront, True) {
  auto result = regexSearchInFront("meow", "meow");
  EXPECT_EQ(result.isMatch, true);
}

TEST(RegexSearchInFront, Fail) {
  auto result = regexSearchInFront("meow", " meow");
  EXPECT_EQ(result.isMatch, false);
}
