#include <iostream>
#include <string>
#include "wordle_functions.hpp"
#include "wordle_functions.cpp"

using namespace std;

int main() {
  string testWord = "CHASE";
  string userInput;

  Greet();
  userInput = GetUserInput();

  DoWordsMatch(userInput, testWord);

  return 0;
}