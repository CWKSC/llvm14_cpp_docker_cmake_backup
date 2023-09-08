#pragma once

#include <iostream>
#include <string>

struct BaseToken {
  std::string string;
  int line;
  int position;
  int length;
  bool isFromGenerate;

  BaseToken() {}
  BaseToken(std::string _string, int _line, int _position, int _length,
            bool _isFromGenerate = false) {
    string = _string;
    line = _line;
    position = _position;
    length = _length;
    isFromGenerate = _isFromGenerate;
  }
  friend std::ostream &operator<<(std::ostream &os, const BaseToken &token);
};
