//
// Created by 邹春旭 on 2020-05-05.
//

#include "arraysort.h"

void ArraySort::mergeSort(int *a, int count) {
    mergeSortC(a, 0, count - 1);
}

void ArraySort::mergeSortC(int *a, int s, int p) {

    if (s >= p) {
        return;
    }

    int d = (s + p) / 2;
    ArraySort::mergeSortC(a, s, d);
    ArraySort::mergeSortC(a, d + 1, p);

    int t = d + 1;
    int i = 0;

    int c = p + 1;
    int arr[c];
    while (s <= d && t <= p) {
        while (s <= d && a[s] < a[t]) arr[i++] = a[s++];

        while (t <= p && a[t] < a[s]) arr[i++] = a[t++];
    }


    while (s <= d) {
        arr[i++] = a[s++];
    }

    while (t <= p) {
        arr[i++] = a[t++];
    }


    for (int j = 0; j <= p; ++j) {
        a[j] = arr[j];
    }

}



