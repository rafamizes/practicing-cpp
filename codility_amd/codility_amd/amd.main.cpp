// Copyright (C) 2013–2022 Free Software Foundation, Inc.
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

#include "solutions.hpp"

int main() {
  /* std::vector<int> data{-1, -3}; */
  /* std::vector<int> data{1, 2, 3}; */
  // [1, 2, 3, 4, 6]
  /* std::vector<int> data{1,  3, 4, 5, 6, 9}; */
  std::vector<int> data{1, 1, 1, 1, 1, 99};
  std::cout << "n: " << amd::smallest_int_does_not_occur(data) << "\n";
  amd::Solution sol(std::cin);
  for (amd::Solution::iterator it = sol.begin(); it != sol.end(); ++it) {
       int x = *it;
       std::cout << x << std::endl;
    }
  return 0;
}
