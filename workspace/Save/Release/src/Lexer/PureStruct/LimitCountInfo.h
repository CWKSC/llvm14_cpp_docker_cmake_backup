#pragma once

struct LimitCountInfo {
  int tokenCount;
  int regexSearchCount;
  int isMinMode;
  LimitCountInfo(int _tokenCount = -1, int _regexSearchCount = -1,
                 int _isMinMode = true) {
    tokenCount = _tokenCount;
    regexSearchCount = _regexSearchCount;
    isMinMode = _isMinMode;
  }
};

