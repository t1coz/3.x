#include "charString.h"
#include "menuCommands.h"
using namespace std;

void CharString :: interface(){
    while(true){
        cout << MAGENTA <<"\nChoose the operation with the string:\n"
                          "1. Set new string ( = );\n"
                          "2. Combine 2 other strings to the initial one ( + );\n"
                          "3. Add another string to initial one ( += );\n"
                          "4. Compare two strings ( == );\n"
                          "5. Completion of the initial string with asterisks ( != );\n"
                          "6. Print specific character ( [] );\n"
                          "7. Print only chosen length ( ()(int, int) ).\n"
                          "8. Show the string;\n\n"
             << RED << "99. Exit the program.\n" << RESET
             << BLUE << "Input: " << RESET;
        int choice;
        while (true){
            if (cin >> choice && (choice>=1 && choice <=8) || choice == 99){
                if (choice == 99){
                    cout << "\n" << RED << "Finishing the program.";
                    return;
                }else{
                    functionsSelection(choice);
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
void CharString :: functionsSelection(int choice){
    char* userString = nullptr;
    int localChoice;
    switch (choice) {
        case 1:{
            cout << "Enter the string: ";
            getStr(&userString);
            *this = userString;
            break;
        }
        case 2:{
            CharString tempSecond, tempThird;
            tempSecond.setString();
            tempThird.setString();
            *this = tempSecond + tempThird;
            cout << "Final string: ";
            this->printString();
            break;
        }
        case 3:{
            CharString tempSecond;
            tempSecond.setString();
            *this += tempSecond;
            cout << "Final string: ";
            this->printString();
            break;
        }
        case 4:{
            CharString tempSecond;
            tempSecond.setString();
            if(*this == tempSecond){
                cout << "The strings are identical.\n";
            }else{
                cout << "The strings are NOT identical.\n";
            }
            break;
        }
        case 5:{
            CharString tempSecond;
            tempSecond.setString();
            if((*this != tempSecond) == 1){
                this->inputAsterisk(tempSecond);
                cout << "Final string: ";
                this->printString();
                break;
            }
            if((*this != tempSecond) == -1){
                cout << "Initial string is greater, than the second.\n";
            }else{
                cout << "Strings are identical in length.\n";
            }
            break;
        }
        case 6:{
            cout << "Which character do you want to print out? (out of "
            << this->getLength() << "): ";
            localChoice = methodOfInput(this->getLength());
            cout << "The character is: " << (*this)[localChoice-1];
            break;
        }
        case 7:{
            int start, end;
            //checkRangeInput(&start, &end);
            if(checkRangeInput(&start, &end) != -1){
                (*this)(start-1, end-1);
            }
            break;
        }
        case 8:{
            cout << "The string is: ";
            this->printString();
            break;
        }
        default: break;
    }
}

//constructors & destructors
CharString::CharString() : CharString(nullptr) {};

CharString::CharString(char* str){
    if(str == nullptr){
        this->length = 0;
        this->str = new char;
        *(this->str) = '\0';
    }else {
        this->length = strlen(str);
        this->str = new char[this->length+ 1];
        strcpy(this->str, str);
    }
}
CharString::CharString(const CharString &str){
    if(str.str == nullptr){
        this->length = 0;
        this->str = new char;
        *(this->str) = '\0';
    }else {
        this->length = strlen(str.str);
        this->str = new char[this->length + 1];
        strcpy(this->str, str.str);
    }
}
CharString::CharString(CharString &&s) noexcept : str{s.str}, length{s.length}{
    s.length = 0;
    s.str = nullptr;
}
CharString :: ~CharString(){delete []str;}

//some methods for the class itself
void CharString::setString(){
    cout << "Enter the string: ";
    char* tString;
    getStr(&tString);
    length = strlen(tString);
    str = new char[length + 1];
    strcpy(str, tString);
}
int CharString :: getLength() const{
    return length;
}
void CharString :: inputAsterisk(const CharString& obj){
    CharString temp("*");
    int difference = obj.length - this->length;
    for (int i = 0; i < difference; i++) {
        *this += temp;
    }
}
void CharString :: printString() const{
    for (int i = 0; i < this->getLength(); i++) {
        cout << str[i];
    }
    cout << "\n";
}
int CharString :: checkRangeInput(int* start, int* end) const{
    cout << "Select start character (out of " << this->length << "): ";
    *start = methodOfInputRange(this->length);
    cout << "Select end character (out of " << this->length <<"): ";
    *end = methodOfInputRange(this->length);
    if (*end <=  *start){
        cout << "The interval is not valid.\n";
        return -1;
    }
    return 0;
}
//overloads
CharString& CharString :: operator=(const CharString &obj){
    if(this != &obj){
        this->length = obj.length;
        this->str = new char[this->length + 1];
        strcpy(this->str, obj.str);
    }
    return *this;
}
CharString CharString::operator+(const CharString &obj){
    CharString finalString;
    finalString.length = this->length + obj.length;
    finalString.str = new char[finalString.length + 1];
    strcpy(finalString.str, this->str);
    strcat(finalString.str, obj.str);
    return finalString;
}
CharString& CharString::operator+=(const CharString &obj){
    // temp save "this" string to other
    CharString other {new char(this->length + 1)};
    strcpy(other.str, this->str);
    this->length = this->length + obj.length;
    this->str = new char[this->length + 1];
    strcpy(this->str, other.str);
    strcat(this->str, obj.str);
    return *this;
}
char CharString::operator[] (int index){
    return str[index];
}

int CharString:: operator==(const CharString& obj)const{
    int result = strcmp(this->str, obj.str);
    if(result == 0){
        return 1;
    }else{
        return 0;
    }
}
int CharString:: operator!=(const CharString& obj)const{
    if(this->length < obj.length){
        return 1;
    }
    if(this->length > obj.length){
        return -1;
    }else{
        return 0;
    }
}
void CharString :: operator()(int start, int end){
    for (int i = start; i < end+1; i++) {
        cout << (*this)[i];
    }
    cout << "\n";
}
