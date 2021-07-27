  #include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int gcd_fast(int a, int b){
  if (a == 0 || b == 0) return std::max(a, b);

  return gcd_fast(b, a % b);
}

long long lcm_fast(int a, int b) {
  int gcd = gcd_fast(a, b);
  return ((long long)a*(long long)b)/(long long)gcd;
}

int main() {
  //testCase();
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a,b) << "\n";
}

int testCase() {
  int a;
  int b;
  int fast;
  int naive;
  for (int i = 0; i < 100; i++) {
    a = rand() % 100;
    b = rand() % 100;
    fast = lcm_fast(a,b);
    naive = lcm_naive(a,b);
    if (fast != naive) {
      printf("ERROR\n");
      printf("A = %i, B = %i\n", a, b);
      printf("Fast = %i\n", fast);
      printf("Naive = %i\n", naive);
      return 0;
    }
    
  }
  printf("All tests passed!\n");
  return 0;
}