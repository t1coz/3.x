#include "menuCommands.h"
#include "list.h"
template <typename T>
void interface(T *list){
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
                    return;
                }else{
                    functionsSelection(choice, list);
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
template<typename T>
void functionsSelection(int choice, LinkedList<T> *list){
    int index;
    T data;
    switch (choice) {
        case 1:{
            cout<<"Enter an item to insert:"<<endl;
            cin>>data;
            (*list).addFront(data);
            break;
        }
        case 2:{
            cout<<"Enter an item to insert:"<<endl;
            cin>>data;
            (*list).add(data);
            break;
        }
        case 3:{
            (*list).removeFront();
            break;
        }
        case 4:{
            (*list).remove();
            break;
        }
        case 5:{
            cout<<"enter index:"<<endl;
            cin>>data;
            cout<<"item at index "<<index<<": "<<(*list).get(index)<<endl;
            break;
        }
        case 6:{
            (*list).displayAll();
            break;
        }
        default: break;
    }
}