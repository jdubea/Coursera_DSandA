#include <iostream>
#include <cassert>

// The following code calls a naive algorithm for computing a Fibonacci number.
//
// What to do:
// 1. Compile the following code and run it on an input "40" to check that it is slow.
//    You may also want to submit it to the grader to ensure that it gets the "time limit exceeded" message.
// 2. Implement the fibonacci_fast procedure.
// 3. Remove the line that prints the result of the naive algorithm, comment the lines reading the input,
//    uncomment the line with a call to test_solution, compile the program, and run it.
//    This will ensure that your efficient algorithm returns the same as the naive one for small values of n.
// 4. If test_solution() reveals a bug in your implementation, debug it, fix it, and repeat step 3.
// 5. Remove the call to test_solution, uncomment the line with a call to fibonacci_fast (and the lines reading the input),
//    and submit it to the grader.

int fibonacci_naive(int n) {
    int result = 0;
    if (n <= 1)
        return n;

    result =  fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
    return result;

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

void test_solution() {
    int res1, res2;
    int test;
    for (int n = 0; n < 20; ++n) {
        test = rand() % 30 + 1;
        printf(" For n = %i\n", test);
        res1 = fibonacci_fast(test);
        res2 = fibonacci_naive(test);
        if (res1 != res2) break;
        printf("Fast == Naive == %i\n", test, res1);
    }
}

int main() {
    int n = 0;
    std::cin >> n;

    //std::cout << fibonacci_naive(n) << '\n';
    std::cout << fibonacci_fast(n) << '\n';

    //test_solution();
    return 0;
}
