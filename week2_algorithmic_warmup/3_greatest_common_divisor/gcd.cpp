#include <iostream>

int gcd_naive(int a, int b) {
  static int count = 0;
  count++;
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  
  return current_gcd;
}

int gcd_fast(int a, int b){
  if (a == 0 || b == 0) return std::max(a, b);

  return gcd_fast(b, a % b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << "Naive: " << gcd_naive(a, b) << "\n";
  std::cout << gcd_fast(a,b) << "\n";
  return 0;
}