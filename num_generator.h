#ifndef NUM_GENERATATOR_H
#define NUM_GENERATATOR_H
#include <iostream>
#include <vector>

using namespace std;

class NumberGenerator {
 private:
  int n, k;
  vector<int *> v;
  void generateUtil(int* arr, int* temp, int index, int i, int n, int k);

 public:
  NumberGenerator(int n, int k);
  ~NumberGenerator() { v.clear(); }
  void print();
  vector<int *> getCombinations();
};

#endif
