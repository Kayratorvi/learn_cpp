#ifndef LAB7ONLINESHOPPINGCART_SHOPPINGCART_H
#define LAB7ONLINESHOPPINGCART_SHOPPINGCART_H

#include <string>
#include "ItemToPurchase.h"
#include <vector>
using namespace std;

class ShoppingCart {
    public:
        ShoppingCart(string name, string date);
        void AddItemToCart(ItemToPurchase item, string name);
        void RemoveItemFromCart(string itemName);
        void UpdateItemQuantity(string itemName, int newQuantity);
        int GetCartQuantity() const;
        double GetTotalCost() const;
        void PrintAllDescriptions() const;
        void PrintNumAndTotalCost() const;
    private:
        string customerName;
        string date;
        vector<ItemToPurchase> cart;
};

#endif //LAB7ONLINESHOPPINGCART_SHOPPINGCART_H
