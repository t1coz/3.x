#ifndef INC_3_3_MENUCOMMANDS_H
#define INC_3_3_MENUCOMMANDS_H
#define GREEN   "\033[32m"
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#include "list.h"
#include "list.cpp"
template<typename T>
void interface(T *list);
template<typename T>
void functionsSelection(int choice, T *list);

#endif
