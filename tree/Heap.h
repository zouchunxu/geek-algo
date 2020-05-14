//
// Created by 邹春旭 on 2020-05-14.
//

#ifndef GEEKAL_HEAP_H
#define GEEKAL_HEAP_H


class Heap {
public:
    Heap(int _count);

    void insert(int value);

    bool exists(int value);

    void del(int value);

    int index(int value);

    ~Heap();


private:
    int count;
    int *data;
    int current;
};


#endif //GEEKAL_HEAP_H
