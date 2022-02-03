// This program allows a user to play Rock, Paper, Scissors, Lizard, 
// Spock! User will enter one of the five options and the computer 
// will choose an option and compare the choices. 

// Live long and prosper!

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

string UserWon(int user, int computer);
string WhoChoseWhat(int user, int computer);
string OutcomeOfChoice(int user, int computer);

int main() {
  srand(time(0));

  int user = 0;
  int computer = 0;
  char again = 'n';

  bool playAgain = false;

  do {
    computer = rand() % 5 + 1;

    cout << "Get ready for Rock, Paper, Scissors, Lizard, Spock!\n";

    cout << "1) Rock\n";
    cout << "2) Paper\n";
    cout << "3) Scissors\n";
    cout << "4) Lizard\n";
    cout << "5) Spock" << endl;

    cin >> user;
    cout << endl;

    while(user < 1 || user > 5) {
      cout << "Invalid entry. Please enter 1-5: ";
      cin >> user;
      cout << endl;
    }

    cout << WhoChoseWhat(user, computer) << UserWon(user, computer);
    cout << OutcomeOfChoice(user, computer) << endl;

    cout << "\nPlay again? Enter y for yes or n for no: ";
    cin >> again;
  } while (again == 'y');

  cout << "\nThanks for playing!" << endl << endl;

  return 0;
}

string UserWon(int user, int computer) {
  bool won = false;
  bool tied = false;

  switch(user) {
    case 1:
      if (computer == 3 || computer == 4) {
        won = true;
      }
      else if (computer == user) {
        tied = true;
      }
      break;
    case 2:
      if (computer == 1 || computer == 5) {
        won = true;
      }
      else if (computer == user) {
        tied = true;
      }
      break;
    case 3:
      if (computer == 2 || computer == 4) {
        won = true;
      }
      else if (computer == user) {
        tied = true;
      }
      break;
    case 4:
      if (computer == 2 || computer == 5) {
        won = true;
      }
      else if (computer == user) {
        tied = true;
      }
      break;
    case 5:
      if (computer == 1 || computer == 3) {
        won = true;
      }
      else if (computer == user) {
        tied = true;
      }
      break;
  }

  if (won && !tied) {
    return "You won! ";
  }
  else if (tied) {
    return "You tied! ";
  }
  else {
    return "You lost! ";
  }
}

string WhoChoseWhat(int user, int computer) {
  string gameChoices[5] = {"Rock", "Paper", "Scissors", "Lizard", "Spock"};
  string output = "";

  --user;
  --computer;

  output = "You chose " + gameChoices[user] + " and the computer chose " + gameChoices[computer] + ". ";
   
  return output;
}

string OutcomeOfChoice(int user, int computer) {
  string output = "";

  if (user == computer) {
    return output;
  }
  
  int val1 = 0, val2 = 0;

  if (user < computer) {
    val1 = user;
    val2 = computer;
  }
  else {
    val1 = computer;
    val2 = user;
  }

  switch (val1) {
    case 1:
      switch (val2) {
        case 2:
          output = "Paper covers Rock.";
          break;
        case 3:
          output = "Rock crushes Scissors.";
          break;
        case 4:
          output = "Rock crushes Lizard.";
          break;
        case 5:
          output = "Spock vaporizes Rock.";
          break;
      }
      break;
    case 2:
      switch (val2) {
        case 3:
          output = "Scissors cuts Paper.";
          break;
        case 4:
          output = "Lizard eats Paper.";
          break;
        case 5:
          output = "Paper disproves Spock.";
          break;
      }
      break;
    case 3:
      switch (val2) {
        case 4:
          output = "Scissors decapitate Lizard.";
          break;
        case 5:
          output = "Spock smashes Scissors.";
          break;
      }
      break;
    case 4:
      if (val2 == 5) {
        output = "Lizard poisons Spock.";
      }
      break;
  }

  return output;
}