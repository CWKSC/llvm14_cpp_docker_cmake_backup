#include "include_std.h"

#include "Printer.h"

namespace PrinterUtil {

void Printer::printLine(std::string value) {
  std::cout << std::string(indent, ' ') << value << std::endl;
}

void Printer::increaseIndent() { indent += indentStep; }

void Printer::decreaseIndent() { indent -= indentStep; }

void Printer::increaseIndent_exceptFirstTime() {
  if (is_increaseIndent_firstTime) {
    is_increaseIndent_firstTime = false;
    return;
  }
  increaseIndent();
}

} // namespace PrinterUtil
