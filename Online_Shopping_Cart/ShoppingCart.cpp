#include <iostream>
#include "ShoppingCart.h"
#include <iomanip>
using namespace std;

ShoppingCart::ShoppingCart(string name = "none", string date = "January 1, 2016") {
    customerName = name;
    this->date = date;
}

void ShoppingCart::AddItemToCart(ItemToPurchase item, string name) {
    bool itemFound = false;

    for (unsigned int i = 0; i < cart.size(); ++i) {
        if (cart.at(i).GetName() == name) {
            cout << "Item is already found in the cart. It will not be added." << endl;
            itemFound = true;
            break;
        }
    }
    if (!itemFound) {
        cart.push_back(item);
    }
}

void ShoppingCart::RemoveItemFromCart(string itemName) {
    bool itemFound = false;

    for(unsigned i = 0; i < cart.size(); ++i) {
        if (itemName == cart.at(i).GetName()) {
            cart.erase(cart.begin() + i);
            itemFound = true;
        }
        if (itemFound) {
            break;
        }
    }

    if (!itemFound) {
        cout << "Item not found in cart. It will not be removed." << endl;
    }
}

void ShoppingCart::UpdateItemQuantity(string itemName, int newQuantity) {
    bool itemFound = false;

    for(unsigned i = 0; i < cart.size(); ++i) {
        if (itemName == cart.at(i).GetName()) {
            cart.at(i).SetQuantity(newQuantity);
            itemFound = true;
        }
        if (itemFound) {
            break;
        }
    }

    if (!itemFound) {
        cout << "Item not found in cart. It will not be modified." << endl;
    }
}

int ShoppingCart::GetCartQuantity() const {
    int total = 0;

    for(unsigned int i = 0; i < cart.size(); ++i) {
        total += cart.at(i).GetQuantity();
    }
    return total;
}

double ShoppingCart::GetTotalCost() const {
    double total = 0.0;

    for(unsigned int i = 0; i < cart.size(); ++i) {
        total += (cart.at(i).GetPrice() * cart.at(i).GetQuantity());
    }
    return total;
}

void ShoppingCart::PrintAllDescriptions() const {
    cout << customerName << "\'s Shopping Cart - " << date << endl;

    if (!cart.empty()) {
        cout << "\nItem Descriptions" << endl;

        for (unsigned int i = 0; i < cart.size(); ++i) {
            cart.at(i).PrintDescription();
        }
    }
    else {
        cout << "Shopping cart is empty." << endl;
    }
}

void ShoppingCart::PrintNumAndTotalCost() const {
    cout << customerName << "\'s Shopping Cart - " << date << endl;

    if (!cart.empty()) {
        cout << "Number of Items: " << ShoppingCart::GetCartQuantity();
        cout << endl << endl;

        for(unsigned int i = 0; i < cart.size(); ++i) {
            cart.at(i).PrintCost();
        }
        cout << "\nTotal: $" << fixed << setprecision(2) << ShoppingCart::GetTotalCost() << endl;
    }
    else {
        cout << "Shopping cart is empty." << endl;
    }
}
