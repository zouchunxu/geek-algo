//
// Created by 邹春旭 on 2020-05-03.
//

#ifndef GEEKAL_LOOPQUEUE_H
#define GEEKAL_LOOPQUEUE_H


template<typename T>
class LoopQueue {
private:
    int tail;
    int head;
    int size;
    T *data;
public:
    LoopQueue(int _size);

    void push(T v);

    T *pop();

    ~LoopQueue();

};


template<typename T>
void LoopQueue<T>::push(T v) {

    if (size == tail && head == 0) {
        return;
    }

    if (size == tail) {
        tail = 0;
    }

    if (tail == head && tail != 0) {
        return;
    }

    data[tail++] = v;

}

template<typename T>
T *LoopQueue<T>::pop() {
    if (size == head) {
        head = 0;
    }
    if (tail == head) {
        return nullptr;
    }

    return &(data[head++]);
}


template<typename T>
LoopQueue<T>::LoopQueue(int _size):size(_size), head(0), tail(0) {
    data = new T[size];
}

template<typename T>
LoopQueue<T>::~LoopQueue() {
    delete[] data;

}


#endif //GEEKAL_LOOPQUEUE_H
