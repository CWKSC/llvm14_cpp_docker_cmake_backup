#pragma once

#include <string>
#include <vector>

#include "../../Common/Token/BaseToken/BaseToken.h"

struct LexingResult {
  std::vector<BaseToken> tokenList;
  std::string remainText;
  LexingResult(std::vector<BaseToken> _tokenList, std::string _remainText) {
    tokenList = _tokenList;
    remainText = _remainText;
  }
};
