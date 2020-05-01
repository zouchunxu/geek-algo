//
// Created by 邹春旭 on 2020-05-01.
//

#ifndef GEEKAL_STACK_H
#define GEEKAL_STACK_H

#include <cstdlib>
#include <iostream>

using namespace std;

template<typename T>
class Stack {
private:
    T *d;
    int curr;
    int size;
public:
    Stack(int n);

    Stack();

    void put(T val);

    bool isEmpty();

    T pop();

    ~Stack();
};

template<typename T>
Stack<T>::Stack(int n) {
    d = new T[n];
    size = n;
    curr = 0;
}

template<typename T>
void Stack<T>::put(T val) {

    if (curr == size) {
        T *n = new T[size * 2];
        memcpy(n, d, sizeof(T) * size);
        delete[] d;
        d = n;
        size = size * 2;
    }

    d[curr++] = val;
}

template<typename T>
T Stack<T>::pop() {
    if (curr < 1) {
        throw std::runtime_error("error");
    }
    return d[--curr];
}


template<typename T>
Stack<T>::~Stack() {
    if (d != nullptr)
        delete[] d;
}

template<typename T>
Stack<T>::Stack(): size(20), curr(0) {
    d = new T[size];
}

template<typename T>
bool Stack<T>::isEmpty() {
    return curr < 1;
}


int calc(const string &str);


#endif //GEEKAL_STACK_H
