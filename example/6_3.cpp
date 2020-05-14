//
// Created by 邹春旭 on 2020-05-14.
//

#include <iostream>
#include "tree/Heap.h"

using namespace std;

int main() {
    Heap h(10);

    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.insert(4);
    h.insert(5);
    h.insert(6);
    h.insert(7);
    h.insert(8);


    cout << h.exists(1) << endl;


    return 0;
}