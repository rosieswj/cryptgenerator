#ifndef EXP_H
#define EXP_H
#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>


using namespace std;

/* interface */
class Expression {
 protected:
  string name;
  double val;
  int* dict;

 public:
  ~Expression(){};
  virtual string get_name() = 0;
  virtual double eval() = 0;
  virtual void store(int* dict) = 0;
};

/* Word Expressions */
class WordExpression : public Expression {
 public:
  WordExpression(string s);
  WordExpression(string s, double v);
  double eval();
  void store(int* dict);
  string get_name();
};

#endif