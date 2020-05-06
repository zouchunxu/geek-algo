//
// Created by 邹春旭 on 2020-05-05.
//

#include <vector>
#include <unordered_map>
#include <map>
#include "arraysort.h"

using namespace std;

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
    int o = s;

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


    for (int j = 0; j < c; ++j) {
        a[o++] = arr[j];
    }

}

void ArraySort::quickSort(int *a, int count) {
    quickSortC(a, 0, count - 1);
}


void ArraySort::quickSortC(int *a, int s, int p) {

    if (s >= p) {
        return;
    }

    int tmp = a[s];
    int begin = s;
    int end = p;
    while (begin < end) {

        while (begin < end && a[end] > tmp) {
            end--;
        }

        if (begin < end) {
            a[begin++] = a[end];
        }


        while (begin < end && a[begin] < tmp) {
            begin++;
        }

        if (begin < end) {
            a[end--] = a[begin];
        }
    }
    a[begin] = tmp;


    quickSortC(a, s, begin);
    quickSortC(a, begin + 1, p);
}




