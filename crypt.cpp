#include "crypt.h" 


Cryptarithm::Cryptarithm(string s) {
    const string SPLIT_AT_EQUAL = "=";
    int split_idx = s.find(SPLIT_AT_EQUAL);
    string l = s.substr(0, split_idx), r = s.substr(split_idx+1);
    left = buildExpression(l);
    right = buildExpression(r);
    alphabet = buildAlphabet(s);
};

vector<char> Cryptarithm::buildAlphabet(string s) {
    vector<char> alphabet;
    int *seen = new int[26];
    for (int i=0; i<s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            if (seen[s[i]-'A'] == 0) {
                seen[s[i]-'A'] = 1;
                alphabet.push_back(s[i]);
            }
        }
    }
    delete[] seen;
    return alphabet;
}

vector<char> Cryptarithm::getAlphabet() {
    return alphabet;
}

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
            words.push_back(w);
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
    if (!checkValidAssignment(dict)) return false; 
    left->store(dict);
    right->store(dict);
    if (fabs(left->eval()-right->eval()) < 0.0001) {
        return true;
    }
    return false;
}

bool Cryptarithm::checkValidAssignment(int *dict) {
    for (string w: words) {
        char firstChar = w[0];
        if (dict[firstChar-'A'] == 0) return false;
    }
    return true;
}

Cryptarithm::~Cryptarithm() {
}
