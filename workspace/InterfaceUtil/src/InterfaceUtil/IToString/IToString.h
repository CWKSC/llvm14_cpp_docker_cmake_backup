#pragma once
#include <include_std.h>

namespace InterfaceUtil {

struct IToString {
  virtual std::string to_string() = 0;
};

} // namespace InterfaceUtil
