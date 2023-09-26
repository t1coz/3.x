#ifndef INC_3_2_CHARSTRING_H
#define INC_3_2_CHARSTRING_H

#include <iostream>
#include <cmath>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
class CharString{
    char *str;
    int length;
public:
    CharString();
    CharString(char* str);
    CharString(const CharString &str);
    CharString(CharString &&s) noexcept;
    ~CharString();

    void interface();
    void functionsSelection(int choice);

    int getLength() const;
    void setString();
    void printString() const;
    void inputAsterisk(const CharString& obj);
    void checkRangeInput(int* start, int* end) const;

    CharString& operator=(const CharString &obj);
    CharString operator+(const CharString &obj);
    CharString& operator+=(const CharString &obj);
    char operator[] (int index);
    void operator()(int start, int end);
    int operator==(const CharString& obj)const;
    int operator!=(const CharString& obj)const;
};

#endif
