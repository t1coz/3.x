#include "list.h"
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
void LinkedList<T>::add(int index, T item){
    if(index > length() || index < 0){
        cout<<"Index is out of range."<<endl;
        return;
    }
    Node<T>* node = new Node<T>[1];
    node->data = item;
    int count = 0;
    Node<T>* temp = head;
    while(temp != NULL && count < index){
        if(count == index-1){
            if(temp->next != NULL){
                node->next = temp->next;
            }
            temp->next = node;
            cout<<"New node has been added at the "<<index<<" index."<<endl;
            break;
        }
        count++;
        temp = temp->next;
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
void LinkedList<T>::remove(int index){
    if(head == NULL){
        cout<<"Linked list is empty."<<endl;
        return;
    }
    if(index >= length() || index < 0){
        cout<<"Index is out of range."<<endl;
        return;
    }
    if(index == 0){
        removeFront();
        cout<<"Item has been removed at "<<index << " index."<<endl;
        return;
    }
    int count = 0;
    Node<T>* temp = head;
    while(temp != NULL){
        if(count == index - 1){
            temp->next = temp->next->next;
            cout<<"Item has been removed at "<<index << " index."<<endl;
            break;
        }
        count++;
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
template <class T>
T* LinkedList<T>::getHead(){ return head;}
