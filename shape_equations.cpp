#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double PI = 3.14;

double CalcRectanglePerimeter(double height, double width);

void PrintRectanglePerimeter(double height, double width);

void DoubleRectanglePerimeter(double& height, double& width);

double CalcCircumferenceOfCircle(double radius);

double CalcAreaOfCircle(double radius);

double CalcVolumeOfSphere(double radius);

void Swap(int& valueA, int& valueB);

void Swap(double& valueA, double& valueB);

int main(){
    double height = 0;
    double width = 0;
    double radius = 0;

    cout << "Enter three numbers for height, width, and radius: ";

    cin >> height >> width >> radius;

    PrintRectanglePerimeter(height, width);
    cout << "... about to double height and width...\n";
    DoubleRectanglePerimeter(height, width);
    PrintRectanglePerimeter(height, width);

    cout << "\nA circle with a radius of " << radius << " has a circumference of " << CalcCircumferenceOfCircle(radius);
    cout << " and an area of " << CalcAreaOfCircle(radius) << endl;

    cout << "A sphere with a radius of " << radius << " has a volume of " << CalcVolumeOfSphere(radius) << endl;

    return 0;
}

double CalcRectanglePerimeter(double height, double width) {
    double perimeter;

    perimeter = (height * 2.0) + (width * 2.0);

    return perimeter;
}

void PrintRectanglePerimeter(double height, double width) {
    cout << fixed << setprecision(1);
    cout << "A rectangle with height " << height << " and width " << width << " has a perimeter of " << CalcRectanglePerimeter(height, width) << "." << endl;
}

void DoubleRectanglePerimeter(double& height, double& width) {
    height = height * 2.0;
    width = width * 2.0;
}

double CalcCircumferenceOfCircle(double radius) {
    double circumference;

    circumference = radius * 2.0 * PI;

    return circumference;
}

double CalcAreaOfCircle(double radius) {
    double area;

    area = radius * radius * PI;

    return area;
}

double CalcVolumeOfSphere(double radius) {
    double volume;

    volume = (4.0 /3.0) * (radius * radius * radius) * PI;

    return volume;
}

void Swap(int& valueA, int& valueB) {
    int valueC;
    int valueD;

    valueC = valueA;
    valueD = valueB;
    valueA = valueD;
    valueB = valueC;
}

void Swap(double& valueA, double& valueB) {
    double valueC;
    double valueD;

    valueC = valueA;
    valueD = valueB;
    valueA = valueD;
    valueB = valueC;
}