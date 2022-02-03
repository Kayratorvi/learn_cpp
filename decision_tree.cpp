#include <iostream>
#include <ctime>
using namespace std;

void UserInputPrompt(char& userChoice, char option1, char option2);

void CougarEatPath(int timeMinsLeft, bool isClassImportant);

void DoorDash();

void NotEnoughTime();

int TimeLostFromTraveling(int& timeMinsLeft);

void WhoCaresAboutClass();

int main() {
    char userChoice;
    int timeMinsLeft = 45;
    bool playAgain = true;
    srand(time(0));

    while (playAgain) {
        cout << "Is class important? Please type t for true or f for false: ";
        cin >> userChoice;
        cout << endl;

        UserInputPrompt(userChoice, 't', 'f');

        bool isClassImportant = (userChoice == 't');

        cout << "You're hungry, and you have 45 minutes before your next class starts.\nYou have to decide what to eat and fast!\n";
        cout << "Do you a) get fast food or b) eat something at home?\n";
        cout << "Please type a or b as the input: ";
        cin >> userChoice;
        cout << endl;

        UserInputPrompt(userChoice, 'a', 'b');

        if (userChoice == 'a') {
            cout << "You decide to get fast food. You only have 45 minutes so it makes sense to save all the time you can.\n";
            cout << "Do you a) go to the Creamery on 9th or b) the Cougareat?\n";
            cout << "Please type a or b as the input: ";
            cin >> userChoice;
            cout << endl;

            UserInputPrompt(userChoice, 'a','b');

            if (userChoice == 'a') {
                cout << "You head to the creamery, but it takes a bit of a walk to get there.\n";
                cout << "You only have " << TimeLostFromTraveling(timeMinsLeft) << " minutes left. ";
                cout << "Once there, you find that the line is to the door!\n";
                cout << "You're not sure if there's enough time to get food before your class starts.\n";
                cout << "Do you a) wait in line or b) grab some groceries to use to make a meal?\n";
                cout << "Please type a or b as the input: ";
                cin >> userChoice;
                cout << endl;

                UserInputPrompt(userChoice, 'a', 'b');

                if (userChoice == 'a' && isClassImportant) {
                    cout << "You get in line at the creamery grill. ";
                    NotEnoughTime();
                }
                else if (userChoice == 'a' && !isClassImportant) {
                    cout << "You get in line at the creamery grill. ";
                    WhoCaresAboutClass();
                }
                else {
                    cout << "After seeing the line you figure there's no way you'll get food in time.\n";
                    cout << "You grab some cereal and ramen for now and head home to eat before class starts.\n\nTHE END" << endl;
                }
            }

            else {
                CougarEatPath(timeMinsLeft, isClassImportant);
            }
        }

        else if(userChoice == 'b' && (rand() % 3) == 2) {
            cout << "You check your pantry for some lunch. You still have some ramen left!\n";
            cout << "Do you a) eat the ramen or b) order DoorDash?" << endl;
            cout << "Please type a or b as the input: ";
            cin >> userChoice;
            cout << endl;

            UserInputPrompt(userChoice, 'a', 'b');

            if(userChoice == 'a') {
                cout << "You decide to make some ramen. It's easy and cheap after all!\n";
                cout << "You have so much time before your class starts that you check the pantry for more snacks!\n";
                cout << "\nTHE END" << endl;
            }

            else {
                DoorDash();
            }
        }

        else {
            cout << "You decide to just eat at home. Why waste money when there's almost definitely food in the pantry?" << endl;
            cout << "You go to take a look but find to your horror that it's empty! Your roommate finished off the ramen.\n";
            cout << "Do you a) run to the Cougareat or b) order DoorDash?" << endl;
            cout << "Please type a or b as the input: ";
            cin >> userChoice;
            cout << endl;

            UserInputPrompt(userChoice, 'a', 'b');

            if(userChoice == 'b') {
                DoorDash();
            }
            else {
                cout << "You lose a bit of time traveling, and now you only have " << TimeLostFromTraveling(timeMinsLeft);
                cout << " minutes left." << endl;

                CougarEatPath(timeMinsLeft, isClassImportant);
            }
        }

        cout << endl << "Play again? Please type y or n as the input: ";
        cin >> userChoice;
        cout << endl;

        UserInputPrompt(userChoice, 'y', 'n');

        if (userChoice == 'n') {
            playAgain = false;
        }
    }

    cout << "Done." << endl;

    return 0;
}

void UserInputPrompt(char& userChoice, char option1, char option2) {
    if (userChoice != option1 && userChoice != option2) {
        while (userChoice != option1 && userChoice != option2) {
            for (int i = 0; i < 3; ++i) {
                for(int j = 4; j > i; --j) {
                    cout << " ";
                }
                for(int j = 0; j <= i; ++j) {
                    cout << "**";
                }
                cout << endl;
            }

            cout << "  ERROR!" << endl;

            for (int i = 3; i > 0; --i) {
                for (int j = 5; j > i; --j) {
                    cout << " ";
                }
                for(int j = 0; j<= i - 1; ++j) {
                    cout << "**";
                }
                cout << endl;
            }
            cout << "\nPlease type " << option1 << " or " << option2 << " as the input: ";
            cin >> userChoice;
            cout << endl;
        }
    }
}

void CougarEatPath(int timeMinsLeft, bool isClassImportant) {
    char userChoice;

    cout << "The Cougareat is a great place to get lunch. It's noon though, so it's busy!\n";
    cout << "Do you a) get in the Chick-fil-a line or b) order from Aloha Plate?" << endl;
    cout << "Please type a or b as the input: ";
    cin >> userChoice;
    cout << endl;

    UserInputPrompt(userChoice, 'a', 'b');

    if((userChoice == 'b' && timeMinsLeft == 45) || (userChoice == 'a' && timeMinsLeft == 30)) {
        cout << "You get in line. The line is crazy long!\nYou get your food with only five minutes before class starts.\n";
        cout << "You'll have to log in to zoom at one of the tables there and eat with the camera off.\n\nTHE END" << endl;
    }

    else if(userChoice == 'a' && timeMinsLeft == 45) {
        cout << "The line at Chick-fil-A seems long but it moves quickly.\nYou get your food with plenty of time to spare!\n";
        cout << "You find a comfortable bench after eating and log in to your class.\n\nTHE END";
    }

    else if (userChoice == 'b' && !isClassImportant && timeMinsLeft == 30) {
        cout << "You get in line at Aloha Plate. ";
        WhoCaresAboutClass();
    }
    else {
        cout << "You get in line at Aloha Plate. ";
        NotEnoughTime();
    }
}

void DoorDash() {
    cout << "You place your order and it arrives five minutes before your class starts.\n";
    cout << "It's expensive, but you've got food now. You start eating, but with your camera off in class of course.\n\n";
    cout << "THE END" << endl;
}

void NotEnoughTime() {
    cout << "How bad could it be?\n";
    cout << "Well, after waiting a while you end up needing to go home.\n";
    cout << "Class is about to start and the line hasn't moved fast enough.\n";
    cout << "You'll just have to eat later.\n\nTHE END" << endl;

}

int TimeLostFromTraveling(int& timeMinsLeft) {
    timeMinsLeft = timeMinsLeft - 15;

    return timeMinsLeft;
}

void WhoCaresAboutClass() {
    cout << "\nYou watch the clock tick past the start time of your next class as you order your food.\n";
    cout << "\"It's much more important that I eat a good meal than it is to attend class,\" you assure yourself.\n";
    cout << "After a bit more waiting, your order comes out and you sit down to eat.\nYou'll just watch the class recording later.\n\n";
    cout << "THE END" << endl;
}