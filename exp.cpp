#include "exp.h"

#include <iostream>
#include <vector>

/* word */
WordExpression::WordExpression(string s) {
  name = s;
  val = 0.0;
}

WordExpression::WordExpression(string s, double v) {
  name = s;
  val = v;
}

double WordExpression::eval() {
  val = 0.0;
  for (int i = 0; i < name.length(); i++) {
    char c = name[i];
    int idx = c - 'a';
    int digit_val = dict[idx];
    val = val * 10 + digit_val;
  }
  return val;
}

void WordExpression::store(int* dict) { this->dict = dict; }

string WordExpression::get_name() { return this->name; }

/* Binary */
