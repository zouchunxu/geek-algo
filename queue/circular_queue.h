//
// Created by 邹春旭 on 2020-05-03.
//

#ifndef GEEKAL_CIRCULAR_QUEUE_H
#define GEEKAL_CIRCULAR_QUEUE_H

#include <cstddef>

template<typename T>
class CircularQueue {
private:
    T *items_ = nullptr;
    size_t capacity_ = 0;
    size_t head_ = 0;
    size_t tail_ = 0;
public:
    CircularQueue() = delete;

    CircularQueue(const size_t capacity) : capacity_(capacity) {
        items_ = new T[capacity_];
    }

    ~CircularQueue() {
        if (items_ != nullptr) {
            delete[] items_;
            items_ = nullptr;
        }
    }

    CircularQueue(const CircularQueue &other) : capacity_(other.capacity_) {
        items_ = new T[capacity_];
        for (int i = other.head_; i < other.tail_; ++i) {
            enqueue(other.items_[i]);
        }
    }

    CircularQueue &operator=(const CircularQueue &rhs) {
        delete[] items_;
        head_ = 0;
        tail_ = 0;
        capacity_ = rhs.capacity_;
        items_ = new T[capacity_];
        for (int i = rhs.head_; i != rhs.tail_; ++i) {
            enqueue(rhs.items_[i]);
        }
        return *this;
    }

    CircularQueue(CircularQueue &&other) : items_(other.items_), capacity_(other.capacity_), head_(other.head_),
                                           tail_(other.tail_) {
        other.items_ = nullptr;
        other.capacity_ = 0;
        other.head_ = 0;
        other.tail_ = 0;
    }

public:
    void enqueue(T item) {
        if ((tail_ + 1) % capacity_ == head_) {
            throw "Push data into a full queue";
        }
        items_[tail_] = item;
        tail_ = (tail_ + 1) % capacity_;
    }

    T head() const {
        if (head_ != tail_) {
            return items_[head_];
        } else {
            throw "Fetch data from an empty queue!";
        }
    }

    void dequeue() {
        if (head_ != tail_) {
            head_ = (head_ + 1) % capacity_;
        } else {
            throw "Pop data from an empty queue";
        }
    }

public:
    template<typename UnaryFunc>
    void traverse(UnaryFunc do_traverse) {
        if (0 == capacity_) return;

        for (int i = head_; i % capacity_ != tail_; ++i) {
            do_traverse(items_[i % capacity_]);
        }
    }


};


#endif //GEEKAL_CIRCULAR_QUEUE_H
