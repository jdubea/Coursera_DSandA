#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  vector<double> val_per_weight;
  for (int i = 0; i < weights.size(); i++) {
    val_per_weight.push_back(values[i]/weights[i]);
//    printf("Item %i: Weight = %i; Value = %i; Val/Wgt = %lf\n", i, weights[i], values[i], val_per_weight[i]);
  }
  for (int i = 0; i < val_per_weight.size(); i++) {
    bool swapped = false;
    for (int j = 0; j < val_per_weight.size() - 1; j++) {
      if (val_per_weight[j] > val_per_weight[j+1]) {
        swapped = true;
        swap(val_per_weight[j], val_per_weight[j+1]);
        swap(weights[j], weights[j+1]);
        swap(values[j], values[j+1]);
      }
    }
    if (!swapped) {
      break;
    }
  }

//  printf("Items Ordered by Val/Weight:\n");
  for (int i = 0; i < weights.size(); i++) {
//    printf("Item %i: Weight = %i; Value = %i; Val/Wgt = %lf\n", i, weights[i], values[i], val_per_weight[i]);
  }

  // write your code here
  while (capacity > 0 && val_per_weight.size() > 0) {
    if (weights.back() >= capacity) {
      value = val_per_weight.back()*capacity;
      weights[weights.size()] = weights.back() - capacity;
      capacity = capacity - capacity;
    }
    else {
      value = val_per_weight.back()*weights.back();
      capacity = capacity - weights.back();
      val_per_weight.pop_back();  
      weights.pop_back();
    }
  }

  return value;
}

int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }
  double optimal_value = get_optimal_value(capacity, weights, values);
  cout.precision(10);
  cout << optimal_value << endl;
  return 0;
}