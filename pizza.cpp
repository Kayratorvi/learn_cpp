#include <iostream>
#include <cmath>
using namespace std;

int main () {
    const double PI = 3.14159265;

    const double LARGE_PIZZA_COST = 14.68;
    const double MEDIUM_PIZZA_COST = 11.48;
    const double SMALL_PIZZA_COST = 7.28;

    const double LARGE_PIZZA_DIAMETER = 20.0;
    const double MEDIUM_PIZZA_DIAMETER = 16.0;
    const double SMALL_PIZZA_DIAMETER = 12.0;

    const int NUM_FED_LARGE_PIZZA = 7;
    const int NUM_FED_MEDIUM_PIZZA = 3;
    const int NUM_FED_SMALL_PIZZA = 1;

    int numPeople = 0;

    cout << "Please enter how many guests to order for: ";
    cin >> numPeople;
    cout << endl;

    int numLargePizzas = 0;
    int numMediumPizzas = 0;
    int numSmallPizzas = 0;
    int numPeopleRemaining = 0;

    numLargePizzas = numPeople / NUM_FED_LARGE_PIZZA;
    numPeopleRemaining = numPeople % NUM_FED_LARGE_PIZZA;

    numMediumPizzas = numPeopleRemaining / NUM_FED_MEDIUM_PIZZA;
    numPeopleRemaining = numPeopleRemaining % NUM_FED_MEDIUM_PIZZA;

    numSmallPizzas = numPeopleRemaining / NUM_FED_SMALL_PIZZA;

    cout << numLargePizzas << " large pizzas, " << numMediumPizzas << " medium pizzas, and " << numSmallPizzas << " small pizzas will be needed." << endl << endl;

    double largePizzaArea = 0.0;
    double mediumPizzaArea = 0.0;
    double smallPizzaArea = 0.0;
    double totalPizzaArea = 0.0;
    double perPersonPizzaArea = 0.0;

    largePizzaArea = pow((LARGE_PIZZA_DIAMETER / 2.0), 2.0) * PI;
    mediumPizzaArea = pow((MEDIUM_PIZZA_DIAMETER / 2.0), 2.0) * PI;
    smallPizzaArea = pow((SMALL_PIZZA_DIAMETER / 2.0), 2.0) * PI;

    totalPizzaArea = (largePizzaArea * numLargePizzas) + (mediumPizzaArea * numMediumPizzas) + (smallPizzaArea * numSmallPizzas);
    perPersonPizzaArea = totalPizzaArea / numPeople;

    cout << "A total of " << totalPizzaArea << " square inches of pizza will be ordered (" << perPersonPizzaArea << " per guest)." << endl << endl;

    int tipPercent = 0;
    double tipCost = 0.0;
    double totalCost = 0.0;

    cout << "Please enter the tip as a percentage (i.e. 10 means 10%): ";
    cin >> tipPercent;
    cout << endl;

    totalCost = (numLargePizzas * LARGE_PIZZA_COST) + (numMediumPizzas * MEDIUM_PIZZA_COST) + (numSmallPizzas * SMALL_PIZZA_COST);
    tipCost = totalCost * (tipPercent * .01);
    totalCost = totalCost + tipCost;
    totalCost = round(totalCost);

    cout << "The total cost of the event will be: $" << static_cast<int>(totalCost) << endl;

    return 0;
}

