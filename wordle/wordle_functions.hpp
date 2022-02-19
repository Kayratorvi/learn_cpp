#include <string>
using namespace std;

void Greet();

string GetUserInput();

bool IsInputLettersOnly(string input);

void CheckUserInput(string& input);

void PrintMisses(vector<char> answer);

void DoWordsMatch(string userInput, vector<char> word);
