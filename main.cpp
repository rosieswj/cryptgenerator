
#include <iostream>
#include <string>
#include <sstream>
#include "binaryexp.h"
#include "num_generator.h"
#include "operator.h"
#include "crypt.h"

void display(int *a, int asize) {
  for (int j = 0; j < asize; j++) {
    // printf("%d ", a[j]);
    cout << a[j] << " " ;
  }
  cout << endl;
}

void displaySolution(int *dict, vector<char> alphabet) {
  cout << "{";
  int n = alphabet.size();
  for (int i=0; i<n; i++) {
    cout << alphabet[i] << "=" << dict[alphabet[i]-'A'] ;
    if (i < n-1) cout << ",";
  }
  cout << "}" << endl;
}

void assign(int *dict, int *permu,  vector<char>alphabet, int k) {
  for (int i=0; i<26; i++) dict[i] = -1;
  for (int i=0; i<k; i++) {
    char c= alphabet[i];
    dict[c-'A'] = permu[i];
  }
}

int main() {
  string s = "SEND + MORE = MONEY";
  // string s = "AABB + CCDD = DDDD";
  Cryptarithm *crypt = new Cryptarithm(s);
  vector<char> alphabet = crypt->getAlphabet();

  const int num_range = 10;  //TODO: CHANGE TO 10
  int alphabet_size = alphabet.size();
  NumberGenerator *gen = new NumberGenerator(num_range, alphabet_size);
  vector<int *> vecs = gen->getCombinations();

  for (int * combo: vecs) {
    /* https://www.geeksforgeeks.org/all-permutations-of-an-array-using-stl-in-c/*/
    sort(combo, combo+alphabet_size);
    int *dict = new int[26];
    do { 
        assign(dict, combo, alphabet, alphabet_size); 
        if (crypt->checkCryptarithm(dict)) {
          displaySolution(dict, alphabet);
        }
    } while (next_permutation(combo, combo + alphabet_size)); 
    // cout << "---------------------------" << endl;
  }
  delete gen;

  return 0;
}



 // int idx = s.find("=");

  // string left = s.substr(0, idx);
  // string right = s.substr(idx+1);
  // cout << left << "|" << right << endl;

  // vector<string> words = getWords(left);
  // for (string s: words) cout << s << endl;


/*
string c = "abc";
  int dict[26];
  for (int i = 0; i < 26; i++) dict[i] = i + 1;
  Expression* e = new WordExpression(c);
  e->store(dict);
  cout << e->eval() << endl;
  cout << e->get_name() << endl;

  Operator* op = new AddOperator();
  cout << *op << endl;

  Expression* binary = new BinaryExpression(e, e, op);
  cout << binary->eval() << endl;
  */

// string c = "abc";
// int dict[26];
// for (int i = 0; i < 26; i++) dict[i] = i + 1;
// Expression* e = new WordExpression(c);
// e->store(dict);
// cout << e->exp() << endl;
// cout << e->eval() << endl;

// int n = 5, k = 4;
// NumberGenerator gen = NumberGenerator(n, k);
// gen.print();
// gen.generate();
// string input = "SEND + MORE = MONEY";