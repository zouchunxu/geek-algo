//
// Created by 邹春旭 on 2020-04-26.
//

#ifndef GEEKAL_LIST_HPP
#define GEEKAL_LIST_HPP

#include <cstdlib>
#include <cstring>

template<typename T>
class List;

template<typename T>
class ListNode {
private:
    T val;
    ListNode *next;
    ListNode *prev;

    friend class List<T>;
};

template<typename T>
class List {
private:
    ListNode<T> *head;
    int size;
public:
    List();

    T *get(int index);

    void put(T val);

    void del(int index);

    void set(int index, T val);

    ~List();
};

template<typename T>
List<T>::List() {
    this->head = new ListNode<T>();
    this->head->next = this->head;
    size = 1;
}


template<typename T>
T *List<T>::get(int index) {
    if (size - 1 < index) {
        return nullptr;
    }

    ListNode<T> *l = this->head;
    for (int i = 0; i <= index; ++i) {
        l = l->next;

        // 末尾
        if (l == this->head) {
            return nullptr;
        }
    }
    return &l->val;
}

template<typename T>
void List<T>::put(T val) {
    ListNode<T> *l = this->head;
    while (l->next != this->head) {
        l = l->next;
    }

    auto *v = new ListNode<T>();
    v->val = val;
    v->prev = l;
    v->next = this->head;
    l->next = v;
    this->head->prev = l->next;
    size++;
}

template<typename T>
void List<T>::set(int index, T val) {
    ListNode<T> *l = this->head;
    for (int i = 0; i <= index; ++i) {
        l = l->next;

        // 末尾
        if (l == this->head) {
            return;
        }
    }

    l->val = val;
}

template<typename T>
void List<T>::del(int index) {
    ListNode<T> *l = this->head;
    for (int i = 0; i <= index; ++i) {
        l = l->next;

        // 末尾
        if (l == this->head) {
            return;
        }
    }

    l->prev->next = l->next;
    l->next->prev = l->prev;
    size--;

    delete l;
}

template<typename T>
List<T>::~List() {
    ListNode<T> *p, *q;
    p = this->head;
    while (p->next != head) {
        q = p->next;
        p->next = p->next->next;
        delete q;
    }
    delete head;
}


#endif //GEEKAL_LIST_HPP
