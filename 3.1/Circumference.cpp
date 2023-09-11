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
                "4. Get the radius value.\n\n"
                << RED << "99. Exit the program.\n" << RESET
                << BLUE << "Input: " << RESET;
        int choice;
        while (true){
            if (cin >> choice && (choice>=1 && choice <=4) || choice == 99){
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
                            cout << "The value of radius is " << getRadius() << "." << endl; break;
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
double Circumference::areaOfCirc(){
    return pow(radius, 2)*M_PI;
}
double Circumference::circumferenceOfCirc(){
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
double Circumference::getRadius(){
    return radius;
}