#include "binaryexp.h"

BinaryExpression::BinaryExpression(Expression *e1, Expression *e2,
                                   Operator *op) {
  this->e1 = e1;
  this->e2 = e2;
  this->op = op;
}

string BinaryExpression::get_name() {
  return e1->get_name() + " " + op->get_symbol() + " " + e2->get_name();
}

double BinaryExpression::eval() { return op->apply(e1, e2); }

void BinaryExpression::store(int *dict) {
  e1->store(dict);
  e2->store(dict);
}