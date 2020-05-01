//
// Created by 邹春旭 on 2020-04-26.
//

#ifndef GEEKAL_LIST_HPP
#define GEEKAL_LIST_HPP

#include <cstdlib>
#include <cstring>
#include <math.h>
#include <iostream>

template<typename T>
class List;

template<typename T>
class ListNode {
public:
    T val;
    ListNode *next;
    ListNode *prev;

    friend class List<T>;
};

template<typename T>
class List {
public:
    ListNode<T> *head;
    int size;

    List();

    T *get(int index);

    void put(T val);

    void del(int index);

    void set(int index, T val);

    void reverse();

    bool isLoop();

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

    bool r = false;

    if (index < 0) {
        index = -index;
        this->reverse();
        r = true;
    }

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


    if (r) {
        this->reverse();
    }


    delete l;
}

template<typename T>
void List<T>::reverse() {
    ListNode<T> *l = this->head->next;
    ListNode<T> *prev = this->head;

    while (l != head) {
        ListNode<T> *n = l->next;

        l->next = prev;
        l->prev = n;

        prev = l;
        l = n;
    }

    this->head->next = prev;
}

template<typename T>
bool List<T>::isLoop() {
    ListNode<T> *slow = this->head->next;
    ListNode<T> *fast = this->head->next;


    while (slow != head) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow) {
            return true;
        }
    }

    return false;
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

template<typename T>
bool isPalindrome(List<T> &list) {
    int mid = ceil((float) list.size / 2);

    ListNode<T> *start = list.head->next;
    ListNode<T> *end = list.head->prev;

    for (int i = 0; i < mid; ++i) {
        if (start->val != end->val) {
            return false;
        }
        start = start->next;
        end = end->prev;
    }
    return true;
}

template<typename T>
bool isPalindromeNoSafe(List<T> l) {
    ListNode<int> *fast = l.head->next;
    ListNode<int> *slow = l.head->next;
    ListNode<int> *prev = l.head->next;

    while (fast->next != l.head) {
        fast = fast->next->next;
        ListNode<int> *next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;

        if (fast == l.head) {
            break;
        }
    }

    if (fast != l.head) {
        slow = slow->next;
    }

    ListNode<int> *cur = prev;
    while (slow != l.head) {
        if (cur->val != slow->val) {
            return false;
        }
        slow = slow->next;
        cur = cur->next;
    }

    return true;
}

#endif //GEEKAL_LIST_HPP
