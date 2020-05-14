//
// Created by 邹春旭 on 2020-05-14.
//

#include "Heap.h"
#include<algorithm>

using namespace std;

void Heap::insert(int value) {
    if (current == count) return;

    data[current++] = value;


    int i = current;
    while (i / 2 > 0) {

        i /= 2;

        if (data[i] < data[i * 2]) swap(data[i], data[i * 2]);

        if (data[i] < data[i * 2 + 1]) swap(data[i], data[i * 2 + 1]);
    }
}



Heap::Heap(int _count) : count(_count) {
    current = 1;
    data = new int[count + 1];
}

Heap::~Heap() {
    delete[] data;
}

bool Heap::exists(int value) {


    int i = 1;

    while (i <= current) {


        if (data[i] == value) {
            return true;
        }

        if (i + 1 <= current && data[i + 1] == value) {
            return true;
        }


        if (data[i] > value) {
            i = i * 2;
        } else {
            return false;
        }

    }


    return false;
}

void Heap::del(int value) {

}
