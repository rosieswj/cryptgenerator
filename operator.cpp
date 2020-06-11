#include "operator.h"

Operator::Operator() { symbol = ""; };

string Operator::get_symbol() { return symbol; }

ostream& operator<<(ostream& os, const Operator& op) {
  os << op.symbol;
  return os;
}

AddOperator::AddOperator() { symbol = "+"; }
double AddOperator::apply(Expression* e1, Expression* e2) {
  return e1->eval() + e2->eval();
}

SubOperator::SubOperator() { symbol = "+"; }
double SubOperator::apply(Expression* e1, Expression* e2) {
  return e1->eval() - e2->eval();
}

MultOperator::MultOperator() { symbol = "*"; }
double MultOperator::apply(Expression* e1, Expression* e2) {
  return e1->eval() * e2->eval();
}

DivOperator::DivOperator() { symbol = "/"; }
double DivOperator::apply(Expression* e1, Expression* e2) {
  return (double)(e1->eval()) / e2->eval();
}
