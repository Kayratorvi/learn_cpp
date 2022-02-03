#ifndef LAB7ONLINESHOPPINGCART_ITEMTOPURCHASE_H
#define LAB7ONLINESHOPPINGCART_ITEMTOPURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase {
public:
    ItemToPurchase();
    ItemToPurchase(string name, string description, double price, int quantity);
    void SetName(string name);
    string GetName() const;
    void SetPrice(double price);
    double GetPrice() const;
    void SetQuantity(int quantity);
    int GetQuantity() const;
    void SetDescription(string description);
    string GetDescription() const;
    void PrintCost() const;
    void PrintDescription() const;
private:
    string itemName;
    double itemPrice;
    int itemQuantity;
    string itemDescription;
};

#endif //LAB7ONLINESHOPPINGCART_ITEMTOPURCHASE_H
