#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int pesos;
  int reais;
  int soles;
  double dollars = 0;

  cout << "Enter number of Colombian Pesos: ";
  cin >> pesos;
  cout << endl;

  cout << "Enter number of Brazilian Reais: ";
  cin >> reais;
  cout << endl;

  cout << "Enter number of Peruvian Soles: ";
  cin >> soles;
  cout << endl;

  // Pesos conversion rate: 0.00025
  // Reais conversion rate: 0.19
  // Soles conversion rate: 0.26

  dollars = (0.00025 * pesos) + (0.19 * reais) + (0.26 * soles);

  cout << "US Dollars = $" << fixed << setprecision(2) << dollars << endl;
  
  return 0;
}