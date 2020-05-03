//
// Created by 邹春旭 on 2020-05-03.
//

#include "queue/queue.h"
#include <iostream>

using namespace std;

int main() {
    Queue<int> q(3);

    q.push(1);
    q.push(2);
    q.pop();
    q.push(3);
    q.push(4);

    cout << *(q.pop()) << endl;
    cout << *(q.pop()) << endl;
    cout << *(q.pop()) << endl;

    return 0;
}