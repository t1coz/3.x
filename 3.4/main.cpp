#include "menuCommands.h"
#include "list.h"

int main(){
    LinkedList<double> list;
    double data;
    int index;
    cout << "List template." << endl;
    while(true){
        cout << MAGENTA <<"\nChoose the operation:\n"
                          "1. Push front;\n"
                          "2. Push back;\n\n"
                          "3. Pop front;\n"
                          "4. Pop back;\n\n"
             <<BLUE<<"5. Display item at index;\n"
                     "6. Display all the items;\n\n"
             << RED << "99. Exit the program.\n\n" << RESET
             << GREEN << "Input: " << RESET;
        int choice;
        while (true){
            if (cin >> choice && (choice>=1 && choice <=6) || choice == 99){
                if (choice == 99){
                    cout << "\n" << RED << "Finishing the program.\n";
                    return 0;
                }else{
                    switch (choice) {
                        case 1:{
                            cout<<"Enter an item to insert:"<<endl;
                            cin>>data;
                            list.addFront(data);
                            break;
                        }
                        case 2:{
                            cout<<"Enter an item to insert:"<<endl;
                            cin>>data;
                            list.add(data);
                            break;
                        }
                        case 3:{
                            list.removeFront();
                            break;
                        }
                        case 4:{
                            list.remove();
                            break;
                        }
                        case 5:{
                            cout<<"Enter the index:"<<endl;
                            cin>>index;
                            cout<<"Item at the index "<<index<<": "<<list.get(index-1)<<"\n";
                            break;
                        }
                        case 6:{
                            list.displayAll();
                            break;
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
