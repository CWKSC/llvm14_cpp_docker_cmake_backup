#pragma once

namespace InterfaceUtil {

template <typename T> struct IEqual { virtual bool equal(T other) = 0; };

} // namespace InterfaceUtil
