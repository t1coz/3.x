#include "menuCommands.h"
#include "media.h"
void interface(Movie *movie, Comic *comic, Show *show, MultiSeasonShow *multiSeasonShow){
    while(true){
        cout << MAGENTA <<"\nChoose the operation:\n"
                          "1. Set new movie;\n"
                          "2. Print movie data;\n\n"
                          "3. Set new comic;\n"
                          "4. Print comic data\n\n"
                          "5. Set new show;\n"
                          "6. Print show data;\n\n"
                          "7. Set new multi season show\n"
                          "8. Print show multi season show;\n\n"
             <<BLUE<<"9. Compare duration of movie with a show;\n"
                     "10.Compare number of episodes in shows;\n"
             << RED << "99. Exit the program.\n\n" << RESET
             << GREEN << "Input: " << RESET;
        int choice;
        while (true){
            if (cin >> choice && (choice>=1 && choice <=10) || choice == 99){
                if (choice == 99){
                    cout << "\n" << RED << "Finishing the program.\n";
                    return;
                }else{
                    functionsSelection(choice, movie, comic, show, multiSeasonShow);
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
void getStr(char **string){
    int size = 0;
    int realSize = 16;
    *string = (char *)malloc(realSize * sizeof(char));
    rewind(stdin);
    char check;
    while (1) {
        check = (char)getchar();
        if (check == '\n') {
            if (size + 1 < realSize) {
                *string = (char *) realloc(*string, (size + 1) * sizeof(char));
            }
            (*string)[size] = '\0';
            return;
        }
        (*string)[size] = check;
        size++;
        if (size + 1 == realSize) {
            realSize *= 2;
            *string = (char *) realloc(*string, realSize * sizeof(char));
        }
    }
}
int methodOfInputRange(int size){
    int num;
    while (scanf("%d", &num) != 1 || (!(num >=1 && num <=size)) || getchar() != '\n') {
        printf("Try better:\n");
        rewind(stdin);
    }
    return num;
}
char yesOrNo(){
    char userAnswer;
    while (1){
        cout << "Make a decision (y/n): " ;
        cin >> userAnswer;
        userAnswer = tolower(userAnswer);
        if (userAnswer == 'y' || userAnswer == 'n')
            break;
        cout << "You may only type 'y' or 'n'.\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return userAnswer;
}