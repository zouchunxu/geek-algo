//
// Created by 邹春旭 on 2020-05-02.
//

#ifndef GEEKAL_LRUCACHE_H
#define GEEKAL_LRUCACHE_H


#include "list.hpp"

using namespace std;

template<typename T>
class LRUCache {
private:
    int size;
    List<pair<string, T>> l;
    int curr;
public:
    LRUCache(int _size);

    void put(string k, T val);

    T *get(string key);

    void del(string key);

    ~LRUCache();
};


template<typename T>
LRUCache<T>::LRUCache(int _size) : size(_size), curr(0) {}

template<typename T>
void LRUCache<T>::put(string k, T val) {

    if (this->get(k) != nullptr) {
        this->del(k);
    }

    if (curr == size) {
        l.head->prev->val = pair<string, T>(k, val);
    } else {

        pair<string, T> p(k, val);

        ListNode<pair<string, T>> *first = l.head->next;

        auto *listNode = new ListNode<pair<string, T>>();
        listNode->val = p;


        l.head->next = listNode;
        first->prev = listNode;
        listNode->next = first;
        listNode->prev = l.head;


        l.head->next = listNode;
        first->prev = listNode;

        curr++;
    }
}

template<typename T>
void LRUCache<T>::del(string key) {
    ListNode<pair<string, T>> *listNode = l.head->next;

    while (listNode != l.head) {

        pair<string, T> p = listNode->val;

        if (p.first == key) {

            listNode->next->prev = listNode->prev;
            listNode->prev->next = listNode->next;


            delete listNode;
            return;
        }
    }

}

template<typename T>
T *LRUCache<T>::get(string key) {

    ListNode<pair<string, T>> *listNode = l.head->next;

    while (listNode != l.head) {

        pair<string, T> p = listNode->val;

        if (p.first == key) {

            ListNode<pair<string, T>> *first = l.head->next;

            l.head->next = listNode;
            first->prev = listNode;


            ListNode<pair<string, T>> *n = listNode->next;
            ListNode<pair<string, T>> *prev = listNode->prev;

            listNode->next = first;
            listNode->prev = l.head;

            prev->next = n;
            n->prev = prev;

            return &(p.second);
        }

        listNode = listNode->next;
    }

    return nullptr;
}

template<typename T>
LRUCache<T>::~LRUCache() {
}


#endif //GEEKAL_LRUCACHE_H
