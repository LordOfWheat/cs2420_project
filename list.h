//
// Created by christinaroesner on 3/11/2024.
//

#ifndef CS2420_PROJECT_LIST_H
#define CS2420_PROJECT_LIST_H

#include <iostream>
#include <memory>
using namespace std;

template <class T>
struct Node {
    Node(T v):value(v),next(nullptr),prev(nullptr){}
    T value;
    Node<T>* next;
    Node<T>* prev;
};

template <class T>
class list;
template <class T>
ostream& operator<<(ostream& out, const list<T> &q);

template <class T>
class list {
    public:
        list();
        bool is_empty();
        int get_count(); // get the count of the list
        int search(T data); // find index of letter
        int search(T data, int iter); // find index of (iter)st letter
        void insert(T data);
        void remove(T data);
        void replace(int index, T data); // to replace selected underscore with correct letter if used by player
        void clear();
        friend ostream& operator<< <>(ostream& out, const list<T> &q);

    private:
        Node<T>* head;
        Node<T>* tail;
        int cnt;
};

template <class T>
list<T>::list() {
    head = nullptr;
    tail = nullptr;
    cnt = 0;
}

template <class T>
bool list<T>::is_empty() {
    return (this->head == nullptr && this->tail == nullptr);
}

template <class T>
int list<T>::get_count() {
    return this->cnt;
}

template <class T>
int list<T>::search(T data) {
    auto temp = this->head;
    int index = 0;

    while (temp != nullptr && temp->value != data) {
        temp = temp->next;
        index++;
    }

    if (temp == nullptr) {
        throw runtime_error("Element not found");
    }
    else {
        return index;
    }
}

template <class T>
int list<T>::search(T data, int iter) {
    auto temp = this->head;
    int index = 0;
    int i = 1;

    while (i != iter+1) {
        while (temp != nullptr && temp->value != data) {
            temp = temp->next;
            index++;
        }

        if (temp == nullptr) {
            throw runtime_error("Element not found");
        }

        i++;

        if (i != iter+1) {
            temp = temp->next;
            index++;
        }
    }
    return index;
}

template <class T>
void list<T>::insert(T data) {
    auto temp = new Node<T>(data);

    if (this->is_empty()) {
        this->head = temp;
        this->tail = temp;
    }
    else {
        this->tail->next = temp;
        temp->prev = this->tail;
        this->tail = temp;
    }

    cnt++;
}

template <class T>
void list<T>::remove(T data) {
    auto temp = this->head;
    while (temp->next != nullptr && temp->value != data) {
        temp = temp->next;
    }

    if (temp->value != data) {
        throw runtime_error("Element was not found");
    }
    else {
        if (temp == this->head && temp == this->tail) {
            this->head = nullptr;
            this->tail = nullptr;
        }
        else {
            if (temp == this->head) {
                this->head = temp->next;
                this->head->prev = nullptr;
            }
            else if (temp == this->tail) {
                this->tail = temp->prev;
                this->tail->next = nullptr;
            }
            else {
                auto temp2 = temp->prev;
                auto temp3 = temp->next;

                temp2->next = temp3;
                temp3->prev = temp2;
            }
        }

        delete temp;
        cnt--;
    }
}

template <class T>
void list<T>::replace(int index, T data) {
    auto temp = this->head;

    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }

    temp->value = data;
}

template <class T>
void list<T>::clear() {
    cnt = 0;
    auto temp = head;

    while (head) {
        head = head->next;
        delete temp;
        temp = head;
    }
}

template <class T>
ostream& operator<<(ostream& out, const list<T> &q) {
    auto temp = q.head;

    while (temp) {
        out << temp->value;
        if (temp->next) {
            out << " ";
        }

        temp = temp->next;
    }

    return out;
}

#endif //CS2420_PROJECT_LIST_H
