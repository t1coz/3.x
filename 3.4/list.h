#ifndef INC_3_4_LIST_H
#define INC_3_4_LIST_H
#include <iostream>

using namespace std;
template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void pushFront(T data);
    void pushBack(T data);

    void popFront();
    void popBack();

    int length();
    void peek(int index);

    void displayAll();
};

template<typename T>
void LinkedList<T>::pushFront(T data) {
    Node<T>* newNode = new Node<T>(data);
    newNode->next = head;
    head = newNode;
    if (tail == nullptr) {
        tail = head;
    }
}
template<typename T>
void LinkedList<T>::pushBack(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}
template<typename T>
void LinkedList<T>::popFront(){
    if (head != nullptr) {
        Node<T>* tempNode = head;
        head = head->next;
        delete tempNode;
        if (head == nullptr) {
            tail = nullptr;
        }
    }
}
template<typename T>
void LinkedList<T>::popBack(){
    if (tail != nullptr) {
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node<T>* tempNode = head;
            while (tempNode->next != tail) {
                tempNode = tempNode->next;
            }
            delete tail;
            tail = tempNode;
            tail->next = nullptr;
        }
    }
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
void LinkedList<T>::peek(int index) {
    Node<T>* tempNode = head;
    int count = 0;
    if(index >= length() || index < 0){
        cout<<"Index is out of range."<< endl;
        return;
    }
    while (tempNode != nullptr && count < index) {
        tempNode = tempNode->next;
        count++;
    }
    if (tempNode != nullptr) {
        cout << "Element at index " << index+1 << ": " << tempNode->data << endl;
    } else {
        cout << "Index out of range." << endl;
    }
}
template<typename T>
void LinkedList<T>::displayAll(){
    if(head == NULL){
        cout<<"Linked list is empty."<<endl;
        return;
    }
    Node<T>* tempNode = head;
    while (tempNode != nullptr) {
        cout << tempNode->data << "; ";
        tempNode = tempNode->next;
    }
    cout << endl;
}
#endif