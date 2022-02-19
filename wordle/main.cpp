#include <iostream>
#include <string>
#include <vector>
#include "wordle_functions.hpp"
#include "wordle_functions.cpp"

using namespace std;

int main() {
  vector<char> testWord = {'c', 'h', 'a', 's', 'e'};
  string userInput;

  Greet();
  userInput = GetUserInput();

  DoWordsMatch(userInput, testWord);

  return 0;
}