#pragma once
#include <ListTreeUtil/include.h>
#include <include_std.h>

namespace CombinatorUtil {

struct Combinator {

  std::unordered_map<std::string, std::any> memory;

  template <typename T> T getMemory(std::string key) {
    return std::any_cast<T>(memory[key]);
  }
  template <typename T> void setMemory(std::string key, T value) {
    memory[key] = value;
  }

  virtual ListTreeUtil::Node *parsing(Combinator &root, Combinator &parent,
                                      ListTreeUtil::IList &list) = 0;
};

} // namespace CombinatorUtil