#include <iostream>
#include <math.h>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int fibonacci_fast(int n) {
    // write your code here
    if (n == 0) return 0;
    if (n == 1) return 1;
    int first = 0;
    int second = 1;
    int current = 0;
    for (int i = 1; i < n; i++){
        current = first + second;
        first = second;
        second = current;
    }
    return current;
}

long pisano(long m) {
    long prev = 0;
    long curr = 1;
    long result = 0;
    for (int i = 0; i < m*m; i++) {
        //printf("Pisano iteratin %i\n", i);
        long temp = 0;
        temp = curr;
        curr = (prev + curr) % m;
        prev = temp;
        if (prev == 0 && curr == 1) {
            result = i + 1;
            //printf("Pisano of %lu == %lu\n", m, result);
            return result;
        }
    }
    return result;
}

long my_fib_fast(long n, long m) {
    // write your code here
    n = n % pisano(m);
    if (n == 0) return 0;
    if (n == 1) return 1;
    long prev = 0;
    long curr = 1;
    long temp = 0;
    for (int i = 0; i < n - 1; i++){
        temp = curr;
        curr = (prev + curr) % m;
        prev = temp;
    }
    return curr % m;
}

void testCase() {
    long fast;
    long naive;
    for (int i = 0; i < 10; i++) {
        printf("Running iteration %i\n", i);
        long m = rand() % 1000 + 2;
        long n = rand() % 100000;
        m = 239;
        n = 2816213588;
        printf("M = %lu, N = %lu\n", m, n);
        fast = my_fib_fast(n, m);
        naive = get_fibonacci_huge_naive(n, m);
        if (fast != naive) {
            printf("ERROR\n");
            printf("Naive = %lu\n", naive);
            printf("Fast = %lu\n", fast);
            return;
        }
    }
}

int main() {

    //testCase();
    long long n, m;
    std::cin >> n >> m;
    std::cout << my_fib_fast(n, m) << '\n';
}
