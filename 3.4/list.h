#ifndef INC_3_4_LIST_H
#define INC_3_4_LIST_H
#include <iostream>
using namespace std;
template<typename T>
class Node{
private:
    T data;
    Node<T>* next;
    template<typename U>friend class LinkedList;
public:
    Node(){this->next = NULL;}
    ~Node(){delete [] next;}
};

template<typename T>
class LinkedList{
private:
    Node<T>* head;
public:
    LinkedList(){this->head = NULL;}
    void add(T item);
    void addFront(T item);
    int length();
    void displayAll();
    void remove();
    void removeFront();
    T get(int index);
    ~LinkedList(){delete [] head;}
};
template<typename T>
void LinkedList<T>::add(T item){
    Node<T>* node = new Node<T>[1];
    node->data = item;
    if(head == NULL){
        head = node;
        cout<<"First node has been added."<<endl;
        return;
    }
    Node<T>* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = node;
    cout<<"New node has been added at the back."<<endl;
}
template<typename T>
void LinkedList<T>::addFront(T item){
    Node<T>* node = new Node<T>[1];
    node->data = item;
    if(head == NULL){
        head = node;
        cout<<"First node has been added."<<endl;
        return;
    }
    node->next = head;
    head = node;
    cout<<"New node has been added at the front."<<endl;
}

template<typename T>
int LinkedList<T>::length(){
    int len = 0;
    Node<T>* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}
template<typename T>
void LinkedList<T>::displayAll(){
    if(head == NULL){
        cout<<"Linked list is empty."<<endl;
        return;
    }
    Node<T>* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"; ";
        temp = temp->next;
    }
}
template<typename T>
void LinkedList<T>::remove(){
    if(head == NULL){
        cout<<"Linked list is empty."<<endl;
        return;
    }
    if(head->next == NULL){
        head = NULL;
        cout<<"Last item has been removed."<<endl;
        return;
    }

    Node<T>* temp = head;
    while(temp != NULL){
        if(temp->next->next == NULL){
            temp->next = NULL;
            cout<<"Last item has been removed."<<endl;
            break;
        }
        temp = temp->next;
    }
}

template<typename T>
void LinkedList<T>::removeFront(){
    if(head == NULL){
        cout<<"Linked list is empty."<<endl;
        return;
    }
    head = head->next;
    cout<<"Front item has been removed."<<endl;
}
template<typename T>
T LinkedList<T>::get(int index){
    if(head == NULL){
        cout<<"Linked list is empty."<< endl;
        return {};
    }
    if(index >= length() || index < 0){
        cout<<"Index is out of range."<< endl;
        return {};
    }
    if(index == 0){
        return head->data;
    }
    int count = 0;
    T res;
    Node<T>* temp = head;
    while(temp != NULL){
        if(count++ == index){
            res = temp->data;
            break;
        }
        temp = temp->next;
    }
    return res;
}

#endif
