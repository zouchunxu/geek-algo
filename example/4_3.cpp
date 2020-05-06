//
// Created by 邹春旭 on 2020-05-06.
//

#include <iostream>
#include "sort/arraysort.h"

using namespace std;


int halt(int a) {
    if (a <= 10) {
        return 10;
    } else if (a <= 50) {
        return 50;
    } else if (a <= 100) {
        return 100;
    } else {
        return 999;
    }
}

int main() {
    int arr[] = {999, 3, 2, 7, 5, 321, 12, 22, 1123, 431};

    int count = sizeof(arr) / sizeof(arr[0]);

    ArraySort::bucketSort(arr, count, halt);

    for (int i = 0; i < count; ++i) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
