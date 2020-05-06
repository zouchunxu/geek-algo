//
// Created by 邹春旭 on 2020-05-06.
//

//
// Created by 邹春旭 on 2020-05-06.
//

#include <iostream>
#include "sort/arraysort.h"

using namespace std;


int halt(char a) {
    if (a >= 97) {
        return 1;
    } else if (a >= 65) {
        return 3;
    } else {
        return 2;
    }
}

int main() {
    char arr[] = "DaFBcAz";

    int count = (sizeof(arr) - 1) / sizeof(arr[0]);

    ArraySort::bucketSort(arr, count, halt);

    for (int i = 0; i < count; ++i) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
