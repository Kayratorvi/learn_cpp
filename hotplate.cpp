#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

const int ARRAY_SIZE = 10;

void PrintArray(const double array[][ARRAY_SIZE]);

void CopyArray(double oldValues[][ARRAY_SIZE], double newValues[][ARRAY_SIZE]);

void IterateArray(double oldValues[][ARRAY_SIZE], double newValues[][ARRAY_SIZE]);

int main() {
    double oldValues[ARRAY_SIZE][ARRAY_SIZE];
    double newValues[ARRAY_SIZE][ARRAY_SIZE];
    bool doAnotherIteration = true;
    ofstream outputFile;
    ifstream inputFile;

    cout << "Hotplate simulator" << endl;
    cout << "\nPrinting the initial plate values..." << endl;

    for(int row = 0; row < ARRAY_SIZE; ++row) {
        for(int column = 0; column < ARRAY_SIZE; ++column) {
            if ((column == 0 || column == ARRAY_SIZE - 1) && (row != 0 && row != ARRAY_SIZE - 1)) {
                newValues[column][row] = 100.0;
            }
            else {
                newValues[column][row] = 0.0;
            }
        }
    }

    CopyArray(oldValues, newValues);

    PrintArray(newValues);

    cout << "\nPrinting plate after one iteration..." << endl;

    IterateArray(oldValues, newValues);

    PrintArray(newValues);

    cout << "\nPrinting final plate..." << endl;

    do {
        CopyArray(oldValues, newValues);
        IterateArray(oldValues, newValues);

        for(int row = 1; row < ARRAY_SIZE - 1; ++row) {
            bool breakLoop = false;

            for(int column = 1; column < ARRAY_SIZE - 1; ++column) {
                if(fabs(oldValues[column][row] - newValues[column][row]) < 0.1) {
                    doAnotherIteration = false;
                    continue;
                }
                else {
                    doAnotherIteration = true;
                    breakLoop = true;
                    break;
                }
            }
            if(breakLoop) {
                break;
            }
        }
    } while (doAnotherIteration);

    PrintArray(newValues);

    cout << endl;
    cout << "Writing final plate to file \"Hotplate.csv\"...\n" << endl;

    outputFile.open("Hotplate.csv");
    if(!outputFile.is_open()) {
        cout << "Failed to open file.\n" << endl;
    }
    else {
        outputFile << fixed << setprecision(3);

        for(int row = 0; row < ARRAY_SIZE; ++row) {
            for(int column = 0; column < ARRAY_SIZE; ++column) {
                outputFile << setw(9) << newValues[row][column];

                if (column < ARRAY_SIZE -1) {
                    outputFile << ",";
                }
            }
            outputFile << endl;
        }
    }

    outputFile.close();

    cout << "Attempting to open file \"Inputplate.txt\" and simulate hotplate..." << endl;

    inputFile.open("Inputplate.txt");

    if(!inputFile.is_open()) {
        cout << "Failed to open file. \n" << endl;
    }
    else {
        for (int row = 0; row < ARRAY_SIZE; row++) {
            for (int column = 0; column < ARRAY_SIZE; column++) {
                inputFile >> newValues[row][column];
            }
        }
        inputFile.close();

        for (int i = 0; i < 3; ++i) {
            CopyArray(oldValues, newValues);
            IterateArray(oldValues, newValues);
        }

        cout << "Printing input plate after 3 updates...\n" << endl;

        PrintArray(newValues);
    }

    return 0;
}

void PrintArray(const double array[][ARRAY_SIZE]) {
    cout << fixed << setprecision(3);

    for(int row = 0; row < ARRAY_SIZE; ++row) {
        for(int column = 0; column < ARRAY_SIZE; ++column) {
            cout << setw(9) << array[row][column];

            if (column < ARRAY_SIZE -1) {
                cout << ",";
            }
        }
        cout << endl;
    }
}

void CopyArray(double oldValues[][ARRAY_SIZE], double newValues[][ARRAY_SIZE]) {
    for(int row = 0; row < ARRAY_SIZE; ++row) {
        for(int column = 0; column < ARRAY_SIZE; ++column) {
            oldValues[row][column] = newValues[row][column];
        }
    }
}

void IterateArray(double oldValues[][ARRAY_SIZE], double newValues[][ARRAY_SIZE]) {
    for(int row = 1; row < ARRAY_SIZE - 1; ++row) {
        for(int column = 1; column < ARRAY_SIZE - 1; ++column) {
            newValues[column][row] = (oldValues[column - 1][row] + oldValues[column][row + 1] + oldValues[column][row - 1] + oldValues[column + 1][row]) / 4.0;
        }
    }
}
