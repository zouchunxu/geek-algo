//
// Created by 邹春旭 on 2020-05-05.
//

#include "sort/arraysort.h"
#include <iostream>

using namespace std;

int main() {

    int count = 5;
    int arr[] = {1, 3, 2, 7, 5};

    ArraySort::mergeSort(arr, count);

    for (int i = 0; i < count; ++i) {
        cout << arr[i] << " ";
    }

    cout << endl;


    return 0;
}

