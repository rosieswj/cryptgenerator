#ifndef CRYPT_H
#define CRYPT_H
#include <iostream>
#include <vector>
#include <set>

#include "exp.h"
#include "operator.h"
#include "binaryexp.h"

class Cryptarithm {
    private: 
        const string TOKENS = "+-*/";
        enum Side { LEFT, RIGHT };
        Expression *left;
        Expression *right;
        Expression * buildExpression(string s);
    
    public:
        ~Cryptarithm();
        Cryptarithm(string s);
        bool checkCryptarithm(int *dict);
};

#endif