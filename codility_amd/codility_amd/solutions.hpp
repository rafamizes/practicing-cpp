#pragma once

#include <iosfwd>
#include <istream>
#include <iterator>
#include <vector>

namespace amd {

// Write a function that, given an array A of N / integers, returns the smallest
// positive integer (greater than 0) that does not occur in A. For example,
// given A = [1, 3, 6, 4, 1, 2], the function should return 5. Given A = [1, 2,
// 3], the function should return 4. Given A = [−1, −3], the function should
// return 1. Write an efficient algorithm for the following assumptions: N is an
// integer within the range [1..100,000]; each element of array A is an integer
// within the range [−1,000,000..1,000,000].
int smallest_int_does_not_occur(std::vector<int>& A);

class Solution {
 public:
  explicit Solution(std::istream& s);
  class iterator;
  iterator begin();
  iterator end();

 private:
  std::istream& _input;
};
class Solution::iterator : public std::iterator<std::input_iterator_tag, int> {
 public:
  explicit iterator(std::istream_iterator<int> iter);
  // pre-increment operator ++i
  iterator& operator++();
  // post-increment operator i++
  iterator operator++(int);
  bool operator==(const iterator& rhs) const noexcept;
  bool operator!=(const iterator& rhs) const noexcept;
  int operator*() const noexcept;

 private:
  std::istream_iterator<int> _iter;
};
}  // namespace amd
