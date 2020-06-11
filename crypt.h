#ifndef CRYPT_H
#define CRYPT_H
#include <iostream>
#include <vector>
#include <set>

#include "exp.h"
#include "operator.h"


class Cryptarithm {
    private: 
        const string TOKENS = "+-*/";
        enum Side { LEFT, RIGHT };

        vector<Expression *> leftExps;
        vector<Expression *> rightExps;
        vector<Operator *> leftOps;
        vector<Operator *> rightOps;

        double evaluate(Side side);
        void buildExpression(string s, Side side);

    public:
        ~Cryptarithm();
        Cryptarithm(string s);
        bool checkCryptarithm(int *dict);
};

#endif