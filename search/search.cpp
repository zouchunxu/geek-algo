//
// Created by 邹春旭 on 2020-05-07.
//

#include <cmath>
#include "search.h"

int Search::binarySearch(const int *a, int value, int count) {
    int low = 0;
    int high = count - 1;

    while (low <= high) {
        int mid = (low + high) / 2;


        if (a[mid] == value) {
            return mid;
        }else if (a[mid] < value) {
            low = mid + 1;
        } else if (a[mid] > value) {
            high = mid - 1;
        }
    }


    return -1;
}
