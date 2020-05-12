//
// Created by 邹春旭 on 2020-05-03.
//

#ifndef GEEKAL_QUEUE_H
#define GEEKAL_QUEUE_H


template<typename T>
class Queue {
private:
    int size;
    int head;
    int tail;
    T *data;
public:
    Queue(int n);

    void push(T val);

    bool isEmpty();

    T *pop();

    ~Queue();

};


template<typename T>
Queue<T>::Queue(int _n):size(_n), head(0), tail(0) {
    data = new T[size];
}

template<typename T>
void Queue<T>::push(T val) {

    if (tail == size) {

        if (head == 0) {
            return;
        }


        for (int i = head; i < tail; ++i) {
            data[i - head] = data[i];
        }

        tail -= head;

        head = 0;
    }

    data[tail++] = val;
}


template<typename T>
T *Queue<T>::pop() {

    if (head == size) {
        return nullptr;
    }

    return &(data[head++]);
}

template<typename T>
Queue<T>::~Queue() {
    delete[] data;
}

template<typename T>
bool Queue<T>::isEmpty() {
    return head == size;
}


#endif //GEEKAL_QUEUE_H
