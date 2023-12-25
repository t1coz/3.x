#include "menuCommands.h"
#include "media.h"
#include "list.h"
#include "exceptions.h"
int main() {
    LinkedList<int> list;
    int data;
    int index;
    cout << "Exceptions." << endl;
    while(true){
        cout << MAGENTA <<"\nChoose the operation:\n"
                          "1. 3Lab(inheritance);\n"
                          "2. 4Lab(templates);\n\n"
             <<RED<< "99. Exit the program.\n\n" << RESET
             <<GREEN<<"Input: " << RESET;
        int choice;
        while (true){
            if (cin >> choice && (choice>=1 && choice <=2) || choice == 99){
                if (choice == 99){
                    cout << "\n" << RED << "Finishing the program.\n";
                    return 0;
                }else{
                    switch (choice) {
                        case 1:{
                            cout << "Media manipulation." << endl;
                            Movie movie;
                            Comic comic;
                            Show show;
                            MultiSeasonShow multiSeasonShow;
                            interface(&movie, &comic, &show, &multiSeasonShow);
                            break;
                        }
                        case 2:{
                            while(true){
                                cout << MAGENTA <<"\nChoose the operation:\n"
                                                  "1. Push front;\n"
                                                  "2. Push back;\n\n"
                                                  "3. Pop front;\n"
                                                  "4. Pop back;\n\n"
                                     <<BLUE<<"5. Display item at index;\n"
                                             "6. Display all the items;\n\n"
                                     <<RED<< "99. Exit the program.\n\n" << RESET
                                     <<GREEN<<"Input: " << RESET;
                                while (true){
                                    if (cin >> choice && (choice>=1 && choice <=6) || choice == 99){
                                        if (choice == 99){
                                            cout << "\n" << RED << "Finishing the program.\n";
                                            return 0;
                                        }else{
                                            try {
                                                switch (choice) {
                                                    case 1:{
                                                        cout<<"Enter an item to insert:"<<endl;
                                                        cin>>data;
                                                        list.pushFront(data);
                                                        break;
                                                    }
                                                    case 2:{
                                                        cout<<"Enter an item to insert:"<<endl;
                                                        cin>>data;
                                                        list.pushBack(data);
                                                        break;
                                                    }
                                                    case 3:{
                                                        list.popFront();
                                                        break;
                                                    }
                                                    case 4:{
                                                        list.popBack();
                                                        break;
                                                    }
                                                    case 5:{
                                                        cout<<"Enter the index:"<<endl;
                                                        cin>>index;
                                                        list.peek(index-1);
                                                        break;
                                                    }
                                                    case 6:{
                                                        list.displayAll();
                                                        break;
                                                    }
                                                    default: break;
                                                }
                                            } catch (Exp error) {
                                                error.show();
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