#ifndef INC_3_4_LIST_H
#define INC_3_4_LIST_H
#include <iostream>
using namespace std;
template<typename T>class Node{
private:
    T data;
    Node<T>* next;
    template<typename U>friend class LinkedList;
public:
    Node(){this->next = NULL;}
};

template<typename T>class LinkedList{
private:
    Node<T>* head;
public:
    LinkedList(){this->head = NULL;}
    void add(T item);
    void addFront(T item);
    void add(int index, T item);
    int length();
    void displayAll();
    void remove();
    void remove(int index);
    void removeFront();
    T get(int index);
    T* getHead();
};
#endif
