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

    if ((tail + 1) % size == head) {
        return;
    }

    data[tail] = v;
    tail = (tail + 1) % size;
}

template<typename T>
T *LoopQueue<T>::pop() {

    if ((head + 1) % size == head) {
        return nullptr;
    }

    T * t =  &(data[head]);
    head = (head + 1) % size;
    return t;
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
