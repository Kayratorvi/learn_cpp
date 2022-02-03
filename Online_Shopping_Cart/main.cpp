#include <iostream>
#include <string>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"
#include "ShoppingCart.cpp"
#include "ItemToPurchase.cpp"
using namespace std;

string GetUserString(const string& prompt);

void AddMenuOption(ShoppingCart& cart);
void RemoveMenuOption(ShoppingCart& cart);
void ChangeMenuOption(ShoppingCart& cart);
void DescriptionsMenuOption(ShoppingCart cart);
void CartMenuOption(ShoppingCart cart);
void OptionsMenuOption();
void QuitMenuOption();


int main() {
    string customerName = GetUserString("Enter Customer's Name: ");
    string todayDate = GetUserString("Enter Today's Date: ");

    ShoppingCart cart(customerName, todayDate);

    string userMenuChoice = "none";
    bool continueMenuLoop = true;
    while (continueMenuLoop) {
        userMenuChoice = GetUserString("\nEnter option: ");

        if (userMenuChoice == "add") {
            AddMenuOption(cart);
        }
        else if (userMenuChoice == "remove") {
            RemoveMenuOption(cart);
        }
        else if (userMenuChoice == "change") {
            ChangeMenuOption(cart);
        }
        else if (userMenuChoice == "descriptions") {
            DescriptionsMenuOption(cart);
        }
        else if (userMenuChoice == "cart") {
            CartMenuOption(cart);
        }
        else if (userMenuChoice == "options") {
            OptionsMenuOption();
        }
        else if (userMenuChoice == "quit") {
            QuitMenuOption();
            continueMenuLoop = false;
        }
        else {
            OptionsMenuOption();
        }
    }

    return 0;
}


string GetUserString(const string& prompt) {
    string userAnswer = "none";

    cout << prompt;
    getline(cin, userAnswer);
    cout << endl;
    return userAnswer;
}
double GetUserDouble(const string& prompt) {
    double userAnswer = 0.0;

    cout << prompt;
    cin >> userAnswer;
    cin.ignore();
    cout << endl;
    return userAnswer;
}
int GetUserInt(const string& prompt) {
    int userAnswer = 0;

    cout << prompt;
    cin >> userAnswer;
    cin.ignore();
    cout << endl;
    return userAnswer;
}


void AddMenuOption(ShoppingCart& cart) {
    string itemName = GetUserString("Enter the item name: ");
    string itemDescription = GetUserString("Enter the item description: ");
    double itemPrice = GetUserDouble("Enter the item price: ");
    int itemQuantity = GetUserInt("Enter the item quantity: ");

    ItemToPurchase newItem(itemName, itemDescription, itemPrice, itemQuantity);

    cart.AddItemToCart(newItem, itemName);
}

void RemoveMenuOption(ShoppingCart& cart) {
    string nameOfItemToRemove = GetUserString("Enter name of the item to remove: ");

    cart.RemoveItemFromCart(nameOfItemToRemove);
}

void ChangeMenuOption(ShoppingCart& cart) {
    string nameOfItemToChange = GetUserString("Enter the item name: ");
    int newItemQuantity = GetUserInt("Enter the new quantity: ");

    cart.UpdateItemQuantity(nameOfItemToChange, newItemQuantity);
}

void DescriptionsMenuOption(ShoppingCart cart) {
    cart.PrintAllDescriptions();
}

void CartMenuOption(ShoppingCart cart) {
    cart.PrintNumAndTotalCost();
}

void OptionsMenuOption() {
    std::cout << "MENU" << endl
              << "add - Add item to cart" << endl
              << "remove - Remove item from cart" << endl
              << "change - Change item quantity" << endl
              << "descriptions - Print the items' descriptions" << endl
              << "cart - Print the shopping cart" << endl
              << "options - Print the options menu" << endl
              << "quit - Quit" << endl << endl;
}

void QuitMenuOption() {
    cout << "Goodbye." << endl;
}