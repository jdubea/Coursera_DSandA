#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct(const vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = (long long)std::max((long long)max_product,
                ((long long)numbers[first]) * ((long long)numbers[second]));
        }
    }

    return max_product;
}

long long MaxPairwiseProductFast(const vector<int> &numbers) {
    long long max_product = 0;
    int n = numbers.size();
    int max1 = 0;
    int max2 = 0;

    max1=std::max(numbers[0], numbers[1]);
    max2=std::min(numbers[0], numbers[1]);

    for (int first = 2; first < n; first++) {
        if (numbers[first] >= max1) {
            max2 = max1;
            max1 = numbers[first];
        }
        else if (numbers[first] > max2) {
            max2 = numbers[first];
        }
    }
    return ((long long)max1)*((long long)max2);
}

int main() {
    int a = 0;
    int b = 0;
    vector<int> input;
    cin >> a;
    for (int i = 0; i < a; i++) {
        cin >> b;
        input.push_back(b); 
    }
    cout << MaxPairwiseProductFast(input) << "\n";
}