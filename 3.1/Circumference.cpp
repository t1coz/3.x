#include <iostream>
#include <cmath>
#include "Circumference.h"
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
using namespace std;

void Circumference::interface(){
    while(true){
        cout << MAGENTA <<"\nChoose the operation with the Circumference:\n"
                "1. Set new radius;\n"
                "2. Calculate an area of the Circumference;\n"
                "3. Calculate a circumference of the Circumference;\n"
                "4. Get the radius value;\n"
                "5. Show all the data together;\n"
                "6. Change radius value;\n"
                "7. Show address of radius value;\n"
                << RED << "99. Exit the program.\n" << RESET
                << BLUE << "Input: " << RESET;
        int choice;
        while (true){
            if (cin >> choice && (choice>=1 && choice <=7) || choice == 99){
                if (choice == 99){
                    cout << "\n" << RED << "Finishing the program.";
                    return;
                }else{
                    switch (choice) {
                        case 1: setRadius(); break;
                        case 2:
                            cout << "Area of the circumference is " << areaOfCirc() <<"." << endl; break;
                        case 3:
                            cout << "Circumference of the circumference is " << circumferenceOfCirc() << "." << endl; break;
                        case 4:
                            displayData(getRadius()); break;
                        case 5:
                            displayData(getRadius(), areaOfCirc(), circumferenceOfCirc()); break;
                        case 6:{
                            Circumference result;
                            double value;
                            cout << "Enter the value: ";
                            cin >> value;
                            *this = *this + value;
                            cout << "New radius is " << this->getRadius() << ".\n";
                        }
                        case 7:
                            cout << "The address of radius is " << &radius << ".\n";

                        default: break;
                    }
                }
                break;
            }else{
                cout << "Invalid Input! Enter the number of operation: ";
                cin.clear();
                while (cin.get() != '\n');
            }
        }
    }
}
double Circumference::areaOfCirc() const{
    return pow(radius, 2)*M_PI;
}
double Circumference::circumferenceOfCirc() const{
    return 2*radius*M_PI;
}
void Circumference::setRadius(){
    double aRadius;
    cout << "Enter a value for the radius of circumference: ";
    while (true) {
        if (cin >> aRadius) {
            radius = aRadius;
            break;
        } else {
            cout << "Invalid Input! Please input a numerical value." << endl;
            cin.clear();
            while (cin.get() != '\n');
        }
    }
}
void Circumference::displayData(double radius){
    cout << "The value of radius is " << radius << ".\n";
}
void Circumference::displayData(double radius, double area, double circumference){
    cout << "The value of radius is " << radius << ".\n";
    cout << "The area is " << area << ".\n";
    cout << "The circumference is " << circumference << ".\n";
}
double Circumference::getRadius() const{
    return radius;
}
Circumference::Circumference(){
    radius = 0;
}
Circumference Circumference::operator+ (double value) const{
    Circumference temp;
    temp.radius = this->radius + value;
    return temp;
}
double* Circumference::operator& (){
    return &this->radius;
}
