/// Copyright 2021.
/// Demonstrates the usage of std::accumulate algorithm.

#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>

int main() {
  // failbit exception not enabled because the failbit is also set when
  // end-of-input occurs.
  /* std::cin.exceptions(std::istream::failbit | std::istream::badbit); */

  // std::fstream input("input.txt");
  int sum = std::accumulate(std::istream_iterator<int>(std::cin),
                            std::istream_iterator<int>(), 0);
  if (std::cin.eof()) {  /// Success! End-of-std::cin has been reached.
    std::cout << "The sum of the ints on the standart input is: " << sum
              << "\n";
  } else if (std::cin.fail()) {
    // if (!input_file.is_open() || input_file.bad()) {
    if (std::cin.bad()) {
      perror("Error reading from standard input");
      return 1;
    } else {
      std::string invalid;
      std::cin.clear();  // resets the error state so that the input can be read
                         // again.
      std::cin >> invalid;
      std::cerr << "Process aborted; invalid input: " << invalid << "\n";
      return 2;
    }
  }
  return 0;
}
