// Copyright 2022
#include "solutions.hpp"

#include <iostream>
#include <set>
#include <utility>
namespace amd {
int smallest_int_does_not_occur(std::vector<int>& A) {
  int smallest = 1;
  std::set<int> sorted{A.begin(), A.end()};
  // erases all values lesser than [smallest].
  sorted.erase(sorted.begin(), sorted.lower_bound(smallest));
  while (sorted.count(smallest) > 0) {
    ++smallest;
  }
  return smallest;
}

/*----- Solution class implementation -----*/

Solution::Solution(std::istream& s) : _input{s} {}

Solution::iterator Solution::begin() {
  return Solution::iterator{std::istream_iterator<int>{_input}};
}
Solution::iterator Solution::end() {
  return Solution::iterator{std::istream_iterator<int>{}};
}
/*----- Iterator implementation -----*/
Solution::iterator::iterator(std::istream_iterator<int> iter)
    : _iter{std::move(iter)} {}

Solution::iterator& Solution::iterator::operator++() {
  ++_iter;
  return *this;
}
// post-increment operator.
Solution::iterator Solution::iterator::operator++(int) {
  iterator tmp(*this);  // copies its current state.
  operator++();         // increments the internal iterator.
  return tmp;           // return its previous state.
}
bool Solution::iterator::operator==(const iterator& rhs) const noexcept {
  return _iter == rhs._iter;
}
bool Solution::iterator::operator!=(const iterator& rhs) const noexcept {
  return !operator==(rhs);
}
int Solution::iterator::operator*() const noexcept { return *_iter; }

}  // namespace amd
