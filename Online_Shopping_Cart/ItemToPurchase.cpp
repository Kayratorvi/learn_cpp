#include "ItemToPurchase.h"
#include <string>
#include <iostream>
#include <iomanip>

ItemToPurchase::ItemToPurchase() {
    itemName = "none";
    itemDescription = "none";
    itemPrice = 0.0;
    itemQuantity = 0;
}

ItemToPurchase::ItemToPurchase(string name, string description, double price, int quantity) {
    itemName = name;
    itemDescription = description;
    itemPrice = price;
    itemQuantity = quantity;
}

void ItemToPurchase::SetName(string name) {
    itemName = name;
}

string ItemToPurchase::GetName() const {
    return itemName;
}

void ItemToPurchase::SetPrice(double price) {
    itemPrice = price;
}

double ItemToPurchase::GetPrice() const {
    return itemPrice;
}

void ItemToPurchase::SetQuantity(int quantity) {
    itemQuantity = quantity;
}

int ItemToPurchase::GetQuantity() const {
    return itemQuantity;
}

void ItemToPurchase::SetDescription(string description) {
    itemDescription = description;
}

string ItemToPurchase::GetDescription() const {
    return itemDescription;
}

void ItemToPurchase::PrintCost() const {
    std::cout << fixed << setprecision(2) << itemName << " " << itemQuantity << " @ $" << itemPrice;
    std::cout << " = $" << (itemQuantity * itemPrice) << endl;
}

void ItemToPurchase::PrintDescription() const {
    std::cout << itemName << ": " << itemDescription << endl;
}

