#ifndef INC_3_5_EXCEPTIONS_H
#define INC_3_5_EXCEPTIONS_H
#include <string>
#include <exception>
#include "iostream"
#include "cstring"

class Exp {
    int code;
    char message[80]{};
public:
    Exp();
    Exp(int , char[]);
    void show();
};


class ExpInput : public Exp {
public:
    ExpInput(int a, char *b) : Exp(a, b){};
};

class ExpFile : public Exp {
public:
    ExpFile() : Exp(){};
    ExpFile(int code_t, char msg_t[80]) : Exp(code_t, msg_t){};
};

class ExpCout : public Exp {
    ExpCout() : Exp(){};
    ExpCout(int code_t, char msg_t[80]) : Exp(code_t, msg_t){};
};


//class Exceptions : public exception {
//private:
//    string errorMessage;
//
//public:
//    Exceptions(){errorMessage = "";};
//    explicit Exceptions(string message) : errorMessage(std::move(message)) {}
//
//    [[nodiscard]] const char *what() const noexcept override {
//        return errorMessage.c_str();
//    }
//};
//class ExceptionInput : public Exceptions {
//private:
//    string errorMessage;
//
//public:
//    explicit ExceptionInput(string message) : errorMessage(std::move(message)) {}
//
//};
//class ExceptionMemory : public Exceptions {
//private:
//    string errorMessage;
//
//public:
//    explicit ExceptionMemory(string message) : errorMessage(std::move(message)) {}
//
//};
#endif //INC_3_5_EXCEPTIONS_H
