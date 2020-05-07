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
        } else if (a[mid] < value) {
            low = mid + 1;
        } else if (a[mid] > value) {
            high = mid - 1;
        }
    }


    return -1;
}

int Search::binarySearchFirst(const int *a, int val, int count) {

    int low = 0;
    int high = count - 1;


    while (low <= high) {

        int mid = low + ((high - low) / 2);
        if (a[mid] >= val) {
            high = mid - 1;
        } else if (a[mid] < val) {
            low = mid + 1;
        }
    }


    if (a[low] < count && a[low] == val) return low;


    return -1;
}

int Search::binarySearchLast(const int *a, int val, int count) {
    int low = 0;
    int high = count - 1;


    while (low <= high) {

        int mid = low + ((high - low) / 2);

        if (a[mid] > val) {
            high = mid - 1;
        } else if (a[mid] <= val) {
            low = mid + 1;
        }
    }


    if (a[high] >= 0 && a[high] == val) return high;

    return -1;
}

int Search::binarySearchLessFirst(const int *a, int val, int count) {

    int low = 0;
    int high = count - 1;


    while (low <= high) {

        int mid = low + ((high - low) >> 1);


        if (a[mid] > val) {
            high = mid - 1;
        } else {
            if (mid == count - 1 || (a[mid + 1] > val)) return mid;
            low = mid +1;
        }


    }


    if (a[low] < count) return low;


    return -1;
}
