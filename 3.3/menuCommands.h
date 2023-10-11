#ifndef INC_3_3_MENUCOMMANDS_H
#define INC_3_3_MENUCOMMANDS_H
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#include "media.h"

void getStr(char **string);
int methodOfInput(int size);
int methodOfInputRange(int size);
void interface(Movie *movie, Comic *comic, Show *show, MultiSeasonShow *multiSeasonShow);
void functionsSelection(int choice, Movie *movie, Comic *comic, Show *show, MultiSeasonShow *multiSeasonShow);
#endif
