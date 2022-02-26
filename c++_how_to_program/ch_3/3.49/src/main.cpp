#include <iostream>

int main() {
  int c;
  if ((c = std::cin.get()) != EOF) {
    main();
    std::cout << static_cast<char>(c);
  }
  return 0;
}
