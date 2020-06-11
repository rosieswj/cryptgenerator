
#include <iostream>

#include "binaryexp.h"
#include "num_generator.h"
#include "operator.h"

int main() {
  
  string s = "SEND + MORE = MONEY";
  int idx = s.find("=");
  cout << idx << endl;
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