
#include "num_generator.h"

#include <iostream>
using namespace std;

NumberGenerator::NumberGenerator(int n, int k) {
  this->n = n;
  this->k = k;
}

void NumberGenerator::print() { cout << "n: " << n << "  k: " << k << endl; }

vector<int *> NumberGenerator::getCombinations() {
  int temp[k];
  int arr[n];
  for (int i = 0; i < n; i++) {
    arr[i] = i;
  }
  generateUtil(arr, temp, 0, 0, n, k);
  return v;
}

void NumberGenerator::generateUtil(int* arr, int* temp, int index, int i, int n,
                                   int k) {
  if (index == k) {
    int* subset = new int[k];
    for (int j = 0; j < k; j++) {
      subset[j] = temp[j];
    }
    v.push_back(subset);
    return;
  }
  if (i >= n) {
    return;
  }
  temp[index] = arr[i];
  generateUtil(arr, temp, index + 1, i + 1, n, k);
  generateUtil(arr, temp, index, i + 1, n, k);
}
