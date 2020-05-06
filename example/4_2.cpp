//
// Created by 邹春旭 on 2020-05-06.
//

#include <iostream>
#include "sort/arraysort.h"

using namespace std;

int main() {


    int arr[] = {1, 3, 2, 7, 5, 321, 12, 22, 1123, 431};
    int count = sizeof(arr) / sizeof(arr[0]);


    ArraySort::quickSort(arr, count);

    for (int i = 0; i < count; ++i) {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}