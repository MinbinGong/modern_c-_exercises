#include <iostream>

unsigned int gcd(unsigned int a, unsigned int b) {
  while (b != 0) {
    unsigned int r = a % b;
    a = b;
    b = r;
  }

  return a;
}

int main() {
  unsigned int a{0}, b{0};
  std::cout << "Input: a = ";
  std::cin >> a;
  std::cout << "Input: b = ";
  std::cin >> b;

  unsigned int gcd_value = gcd(a, b);
  std::cout << "gcd(" << a << ", " << b << ") = " << gcd_value << std::endl;

  return 0;
}
