#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int fibonacci_lst_digit_fast(int n) {
    // write your code here
    if (n == 0) return 0;
    if (n == 1) return 1;
    int first = 0;
    int second = 1;
    int current = 0;
    for (int i = 1; i < n; i++){
        int temp = -;
        current = (first + second) % 10;
        first = second;
        second = current;
    }
    return current;
}

int main() {
    int n;
    std::cin >> n;
    int c = fibonacci_lst_digit_fast(n);
    std::cout << c << '\n';
    }
