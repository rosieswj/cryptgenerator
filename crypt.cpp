#include "crypt.h" 
#include <sstream>


Cryptarithm::Cryptarithm(string s) {
    const string SPLIT_AT_EQUAL = "=";
    int split_idx = s.find(SPLIT_AT_EQUAL);
    string left = s.substr(0, split_idx), right = s.substr(split_idx+1);
    
    buildExpression(left, LEFT);
    buildExpression(right, RIGHT);

    /*
    cout << left << ", " << right << endl;
    cout << leftExps.size() << ", ops: " << leftOps.size() << endl;
    cout << rightExps.size() << ", ops: " << rightOps.size() << endl;
    */
};


void Cryptarithm::buildExpression(string s, Side side) {
    string buf;                 // Have a buffer string
    vector<string> tokens;
    vector<Operator *> ops;
    vector<Expression *> exps;
    stringstream ss(s);       // Insert the string into a stream
    while (ss >> buf)
    tokens.push_back(buf);
    for (string w: tokens) {
        if (TOKENS.find(w) == string::npos) {   //is an expression
            exps.push_back(new WordExpression(w));
        }
        else {  //is an op
            if (w.compare("+") == 0)  ops.push_back(new AddOperator());
            else if (w.compare("-") == 0)  ops.push_back(new SubOperator());
            else if (w.compare("*") == 0)  ops.push_back(new MultOperator());
            else if (w.compare("/") == 0)  ops.push_back(new DivOperator());
        }
    }   
    if (side == LEFT) {
        leftExps = exps;
        leftOps = ops;
    }
    else {
        rightExps = exps;
        rightOps = ops;
    }
}


bool Cryptarithm::checkCryptarithm(int *dict) {
    return true;
}

Cryptarithm::~Cryptarithm() {
    leftExps.clear();
    rightExps.clear();
    leftOps.clear();
    rightOps.clear();
}
