#pragma once

#include <string>

#include "../BaseToken/BaseToken.h"

struct TaggedToken {
  std::string tag;
  BaseToken baseToken;

  TaggedToken() {}
  TaggedToken(std::string _tag, BaseToken _baseToken) {
    tag = _tag;
    baseToken = _baseToken;
  }

  friend std::ostream &operator<<(std::ostream &os, const TaggedToken &token);
};
