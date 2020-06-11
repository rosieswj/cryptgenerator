
#include <iostream>
#include <string>
#include <sstream>
#include "binaryexp.h"
#include "num_generator.h"
#include "operator.h"
#include "crypt.h"

int main() {
  
  string s = "SEND + MORE = MONEY";
  Cryptarithm *crypt = new Cryptarithm(s);

  // int idx = s.find("=");

  // string left = s.substr(0, idx);
  // string right = s.substr(idx+1);
  // cout << left << "|" << right << endl;

  // vector<string> words = getWords(left);
  // for (string s: words) cout << s << endl;

  return 0;
}





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