#include <iostream>
using namespace std;
int get_change(int m) {
  //write your code here
  int n = 0;
  while (m > 0) {
    while (m >= 10) {
      n++;
      m = m -10;
    }
    while (m >= 5) {
      n++;
      m = m - 5;
    }
    if (m >= 1) {
      n++;
      m = m-1;
    }

  }
  return n;
}

int main() {
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}
