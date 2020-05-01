//
// Created by 邹春旭 on 2020-05-01.
//
#include "stack/stack.h"
#include <iostream>

using namespace std;

int main() {

    Stack<int> s(2);

    s.put(1);
    s.put(2);
    s.put(3);

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    return 0;
}