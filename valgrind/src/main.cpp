/**
 * Copyright © 2020 Platis Platform.
 */
#include <iostream>
#include <memory>

int main() {
  std::cout << "Leaking program has begun.\n";
  std::cout << "Leaking program has finished.\n";
  /* int* ptr = new int[10]; */
  /* ptr[10] = 10; */
  /* std::cout << "Invalid value: " << ptr[10] << "\n"; */
  return -9;
}
