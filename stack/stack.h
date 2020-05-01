//
// Created by 邹春旭 on 2020-05-01.
//

#ifndef GEEKAL_STACK_H
#define GEEKAL_STACK_H

#include <cstdlib>

template<typename T>
class Stack {
private:
    T *d;
    int curr;
    int size;
public:
    Stack(int n);

    void put(T val);

    T pop();

    ~Stack();
};

template<typename T>
Stack<T>::Stack(int n) {
    d = (T *) (malloc(n * sizeof(T)));
    size = n;
    curr = 0;
}


template<typename T>
void Stack<T>::put(T val) {
    d[curr] = val;
    curr++;
}

template<typename T>
T Stack<T>::pop() {

    T v = d[0];
    for (int i = 0; i < curr; ++i) {
        d[i] = d[i + 1];
    }
    curr--;
    size--;

    return v;
}

template<typename T>
Stack<T>::~Stack() {
    if (d != nullptr)
        delete[] d;
}


#endif //GEEKAL_STACK_H
