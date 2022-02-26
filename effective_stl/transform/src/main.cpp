/// Copyright 2021.
/// stl transform algorithm example. It prints to std::cout the length of each
/// string in a set.

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

/// Functor class that retrives incoming string's size.
class StringSize final {
 public:
  std::string::size_type operator()(const std::string& s) const noexcept {
    return s.size();
  }
};

int main() {
  /// Improves performance of cin and cout by not synchronizing with printf and
  // scanf set of functions.
  std::ios_base::sync_with_stdio(false);
  /// cin and cout are tied together by default. Performing a read on cin first
  /// flushes cout if it has buffered data waiting to be output
  std::cin.tie(nullptr);
  std::cout << "Enter a list of words (Ctrl-d or end-of-file to terminate)."
            << std::endl;  // endl is necessary because cin and cout have been
                           // untied from each other.
  const auto words =
      std::vector<std::string>(std::istream_iterator<std::string>(std::cin),
                               std::istream_iterator<std::string>());
  std::cout << "\nThe length of each word:" << std::endl;
  std::transform(words.begin(), words.end(),
                 std::ostream_iterator<std::string::size_type>(std::cout, "\n"),
                 StringSize());
  // std::mem_fn(&std::string::size));
  return 0;
}
