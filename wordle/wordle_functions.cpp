#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void Greet() {
  cout << "\nWelcome to Wordle for C++!\n\n*** Instructions ***" << endl
       << "Type in five letters to guess the word in a maximum of six tries.\n"
       << "After each try you'll be told how many letters match.\n"
       << "O = Perfect match   * = Letter exists but not in this spot   X = Letter is not present\n\n";
}

string GetUserInput() {
  string answer;

  cout << "Please type in your guess. Must be a five letter word: ";
  cin >> answer;
  cout << endl;
  CheckUserInput(answer);

  return answer;
}

bool IsInputLettersOnly(string input) {
  bool isWord = all_of(begin(input), end(input),
    [](char c){ return isalpha(c); });
  
  return isWord;
}

void CheckUserInput(string& input) {
  
  while (input.length() != 5 || !IsInputLettersOnly(input)) {
    if (input.length() != 5) {
      cout << "Unexpected word length. Please type in a word that only has five letters: ";
      cin >> input;
      cout << endl;
    }
    if (!IsInputLettersOnly(input)) {
      cout << "Your word contains numbers! Please only use letters: ";
      cin >> input;
      cout << endl;
    }
  }
}

void PrintMisses(vector<char> answer) {
  for (unsigned int i = 0; i < answer.size(); ++i) {
    cout << answer.at(i) << " ";
  }
  cout << endl;
}

void DoWordsMatch(string userInput, vector<char> word) {
  vector<char> answer = {'X', 'X', 'X', 'X', 'X'};

  for (unsigned int i = 0; i < userInput.length(); i++) {
    if (userInput.at(i) == word.at(i)) {
      answer.at(i) = 'O';
    }
    else {
      for (unsigned int j = 0; j < word.size(); ++j) {
        if (userInput.at(i) == word.at(j)) {
          answer.at(i) = '*';
        }
      }
    }
  }

  PrintMisses(answer);
}