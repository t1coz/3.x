#ifndef INC_3_4_LIST_H
#define INC_3_4_LIST_H

#include <iostream>
#include "exceptions.h"
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
    Node<T>* newNode;
    try {
        newNode = new Node<T>(data);
    }
    catch (std::bad_alloc &badAlloc) {
        throw Exp(100, "Not enough memory");
    }
    newNode->next = head;
    head = newNode;
    if (tail == nullptr) {
        tail = head;
    }
}
template<typename T>
void LinkedList<T>::pushBack(T data) {
    Node<T>* newNode;
    try {
        newNode = new Node<T>(data);
    }
    catch (std::bad_alloc &badAlloc) {
        throw Exp(100, "Not enough memory");
    }
    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}
template<typename T>
void LinkedList<T>::popFront(){
    if (head == nullptr) {
        throw Exp(101, "List is empty");
    }
    Node<T>* tempNode = head;
    head = head->next;
    delete tempNode;
    if (head == nullptr) {
        tail = nullptr;
    }
}
template<typename T>
void LinkedList<T>::popBack(){
    if (tail == nullptr) {
        throw Exp(101, "List is empty");
    }
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
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
        throw Exp(200, "Index is out of range");
    }
    while (tempNode != nullptr && count < index) {
        tempNode = tempNode->next;
        count++;
    }
    if (tempNode != nullptr) {
        cout << "Element at index " << index+1 << ": " << tempNode->data << endl;
    } else {
        throw Exp(200,"Index is out of range");
    }
}
template<typename T>
void LinkedList<T>::displayAll(){
    if (head == nullptr) {
        throw Exp(101,"List is empty");
    }
    Node<T>* tempNode = head;
    while (tempNode != nullptr) {
        cout << tempNode->data << "; ";
        tempNode = tempNode->next;
    }
    cout << endl;
}
#endif