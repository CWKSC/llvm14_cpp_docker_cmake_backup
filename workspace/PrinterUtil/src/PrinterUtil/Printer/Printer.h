#pragma once
#include "include_std.h"

namespace PrinterUtil {

struct Printer {
  int indent = 0;
  int indentStep = 4;
  bool is_increaseIndent_firstTime = true;
  void printLine(std::string value);
  void increaseIndent();
  void decreaseIndent();
  void increaseIndent_exceptFirstTime();
};

} // namespace PrinterUtil