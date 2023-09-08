#pragma once

#include <string>

struct CaptureGroup {
  std::string matchString;
  int length;
  int position;
  CaptureGroup(std::string _matchString, int _length, int _position) {
    matchString = _matchString;
    length = _length;
    position = _position;
  }
};
