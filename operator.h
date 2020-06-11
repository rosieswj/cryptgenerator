#ifndef OPERATOR_H
#define OPERATOR_H
#include <iostream>
#include <vector>

#include "exp.h"

using namespace std;

class Operator {
 protected:
  string symbol;

 public:
  Operator();
  string get_symbol();
  virtual double apply(Expression *e1, Expression *e2) = 0;
  friend ostream &operator<<(ostream &os, const Operator &op);
};

class AddOperator : public Operator {
 public:
  AddOperator();
  double apply(Expression *e1, Expression *e2);
};

class SubOperator : public Operator {
 public:
  SubOperator();
  double apply(Expression *e1, Expression *e2);
};

class MultOperator : public Operator {
 public:
  MultOperator();
  double apply(Expression *e1, Expression *e2);
};

class DivOperator : public Operator {
 public:
  DivOperator();
  double apply(Expression *e1, Expression *e2);
};

#endif