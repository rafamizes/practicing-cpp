// Copyright 2022
//
// The purpose of this problem is to verify whether the method you are using to
// read input data is sufficiently fast to handle problems branded with the
// enormous Input/Output warning. You are expected to be able to process at
// least 2.5MB of input data per second at runtime.

// Input
//
// The input begins with two positive integers n k (n, k<=107). The next n lines
// of input contain one positive integer ti, not greater than 109, each.

// Output
//
// Write a single integer to output, denoting how many integers ti are divisible
// by k.
//
// Example
//
// Input:
// 7 3
// 1
// 51
// 966369
// 7
// 9
// 999996
// 11
//
// Output:
// 4

#include <bits/stdc++.h>
#include <iostream>

/// Functor that counts how many integers 'ti' are divisible by 'k'.
class DivCount final {
 public:
  /// Sets the divider value.
  explicit constexpr DivCount(int k) noexcept : k_{k} {}

  inline int operator()(int curr, int ti) const noexcept {
    return ti % k_ == 0 ? ++curr : curr;
  }

 private:
  const int k_;
};
int main() {
  // Improves the performance of cin and cout by not synchronizing with printf
  // and scanf set of functions.
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, k;
  std::cin >> n >> k;
  std::cout << std::accumulate(std::istream_iterator<int>{std::cin},
                               std::istream_iterator<int>(), 0, DivCount{k})
            << "\n";
  return 0;
}
