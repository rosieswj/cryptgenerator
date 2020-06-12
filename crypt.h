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
        vector<string> words;
        Expression *left;
        Expression *right;
        Expression * buildExpression(string s);
        vector<char> alphabet;
        vector<char> buildAlphabet(string s);
        bool checkValidAssignment(int *dict);
    
    public:
        ~Cryptarithm();
        Cryptarithm(string s);
        const static int ALPHABET_MAX_SIZE = 26;
        const static int ALPHABET_RANGE = 10;
        const static char ALPHABET_START = 'A';
        const static char ALPHABET_END = 'Z';
        bool checkCryptarithm(int *dict);
        vector<char> getAlphabet();
        void solve();
};

#endif