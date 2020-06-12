
#include <iostream>
#include <string>
#include <sstream>
#include "binaryexp.h"
#include "num_generator.h"
#include "operator.h"
#include "crypt.h"

/* helper: print int array of size asize*/
void display(int *a, int asize) {
  for (int j = 0; j < asize; j++) {
    cout << a[j] << " " ;
  }
  cout << endl;
}

/* helper: get Cryptarithm formatted solution */
string formatSolution(int *dict, vector<char> alphabet) {
  string res = "{";
  int n = alphabet.size();
  for (int i=0; i<n; i++) {
    res += alphabet[i];
    res += "=";
    res += std::to_string(dict[alphabet[i]-'A']);
    if (i < n-1) res+= ",";
  }
  res += "}";
  return res;
}

/* helper: assign permuatation of ints as values to the 
   characters in alphabet  */
void assign(int *dict, int *permu, vector<char>alphabet, int k) {
  for (int i=0; i< Cryptarithm::ALPHABET_MAX_SIZE; i++) dict[i] = -1;
  for (int i=0; i<k; i++) {
    char c= alphabet[i];
    dict[c-'A'] = permu[i];
  }
}

/* helper: format printing */
void displaySolution(vector<string> sols) {
  if (sols.size() == 0) {
    cout << "0 solution(s)" << endl;
    return;
  }
  cout << sols.size() << " solution(s): " << endl;
  for (string s : sols) {
    cout << s << endl;
  }
}

void solve(string s) {
  Cryptarithm *crypt = new Cryptarithm(s);
  vector<char> alphabet = crypt->getAlphabet();
  int cur_size = alphabet.size();
  int *dict = new int[Cryptarithm::ALPHABET_MAX_SIZE];
  NumberGenerator *gen = new NumberGenerator(Cryptarithm::ALPHABET_RANGE, cur_size);
  vector<string> solutions; 
  for (int * combo: gen->getCombinations()) {
    /* https://www.geeksforgeeks.org/all-permutations-of-an-array-using-stl-in-c/*/
    sort(combo, combo+cur_size);
    do { 
        assign(dict, combo, alphabet, cur_size); 
        if (crypt->checkCryptarithm(dict)) {
          solutions.push_back(formatSolution(dict, alphabet));
        }
    } while (next_permutation(combo, combo + cur_size)); 
  }
  displaySolution(solutions);
  delete gen;
}

int main() {
  string input = "";
  string EXIT = "q";

  while (1) {
    cout << "enter Cryptarithm expression | enter 'q' to exit:" << endl;
    getline(cin, input);
    if (input.compare(EXIT) == 0) break;
    if (input.find("=") == string::npos) {
      cout << "Error: Cryptarithm must be of the form EXPRESSION = EXPRESSION " << endl;
    }
    else {
      //to upper case
      string s= "";
      for (char c: input) {
        if (c >= 'a' && c <= 'z') {
          s += toupper(c);
        }
        else {
          s += c;
        }
      }
      solve(s);
      input.clear();
    }
  }
  return 0;
}

