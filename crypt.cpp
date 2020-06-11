#include "crypt.h" 
#include <sstream>


Cryptarithm::Cryptarithm(string s) {
    const string SPLIT_AT_EQUAL = "=";
    int split_idx = s.find(SPLIT_AT_EQUAL);
    string l = s.substr(0, split_idx), r = s.substr(split_idx+1);
    left = buildExpression(l);
    right = buildExpression(r);
};


Expression * Cryptarithm::buildExpression(string s) {
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
    Expression *temp = exps[0];
    for (int i=1; i<exps.size(); i++) {
        temp = new BinaryExpression(temp, exps[i], ops[i-1]);
    } 
    return temp;
}

bool Cryptarithm::checkCryptarithm(int *dict) {
    left->store(dict);
    right->store(dict);
    cout << left->get_name() << ": " << left->eval() << endl;
    cout << right->get_name() << ": " << right->eval() << endl;
    return true;
}

Cryptarithm::~Cryptarithm() {
}
