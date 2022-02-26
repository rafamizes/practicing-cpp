/// Copyright 2021.
/// Tests the nth_element algorithm from std library.

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <vector>

#include "../../stream_container.hpp"

class SeqGen final {
 public:
  explicit SeqGen(int start = 1) : _accu(start) {}

  int operator()() noexcept { return ++_accu; }

 private:
  int _accu;
};

int main() {
  std::vector<int> random10(10);
  auto i = random10.at(-1);
  std::generate(random10.begin(), random10.end(), SeqGen());
  std::random_shuffle(random10.begin(), random10.end());

  effec_stl::StreamContainer scont;
  std::cout << "Container values before nth_element: ";
  scont << random10;

  std::cout << "Container values after nth_element.: ";
  const auto seventh = random10.begin() + 6;
  std::nth_element(random10.begin(), seventh, random10.end());
  scont << random10;
  return 0;
}
