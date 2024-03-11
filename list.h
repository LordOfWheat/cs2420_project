//
// Created by christinaroesner on 3/11/2024.
//

#ifndef CS2420_PROJECT_LIST_H
#define CS2420_PROJECT_LIST_H

template <class T>
struct Node {
    Node(T v):value(v),next(nullptr),prev(nullptr){}
    T value;
    Node<T>* next;
    Node<T>* prev;
};

class list {
public:
    
private:

};


#endif //CS2420_PROJECT_LIST_H
