#ifndef BINARY_EXP_H
#define BINARY_EXP_H
#include <iostream>
#include <vector>

#include "exp.h"
#include "operator.h"

using namespace std;

class BinaryExpression : public Expression {
 private:
  Expression *e1;
  Expression *e2;
  Operator *op;

 public:
  BinaryExpression(Expression *e1, Expression *e2, Operator *op);
  string get_name();
  double eval();
  void store(int *dict);
};

#endif
