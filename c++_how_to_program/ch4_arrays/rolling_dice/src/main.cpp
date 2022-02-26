/// Copyright © 2021.
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

int main() {
  const int arraySize = 7;
  int frequency[arraySize] = {0};
  srand(static_cast<unsigned>(time(0)));

  for (int roll = 1; roll <= 6000; roll++) {
    ++frequency[1 + rand() % 6];
  }
  std::cout << "Face" << std::setw(13) << "Frequency"
            << "\n";

  for (int face = 1; face < arraySize; face++) {
    std::cout << std::setw(4) << face << std::setw(13) << frequency[face]
              << "\n";
  }
  std::cout << std::endl;
  return 0;
}
