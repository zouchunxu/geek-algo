//
// Created by 邹春旭 on 2020-05-07.
//

#include "search/search.h"
#include <iostream>

using namespace std;

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int c = sizeof(arr) / sizeof(arr[0]);

    cout << Search::binarySearch(arr, 3, c) << endl;


    int arr1[] = {1, 2, 3, 3, 4, 5, 6, 7, 8};
    int c1 = sizeof(arr) / sizeof(arr1[0]);
    cout << Search::binarySearchFirst(arr1, 3, c1) << endl;

    int arr2[] = {1, 2, 3, 3, 4, 5, 6, 7, 8};
    int c2 = sizeof(arr) / sizeof(arr2[0]);
    cout << Search::binarySearchLast(arr2, 3, c2) << endl;


    int arr3[] = {1, 2, 3, 3, 5, 6, 7, 8};
    int c3 = sizeof(arr) / sizeof(arr3[0]);
    cout << Search::binarySearchLessFirst(arr3, 4, c3) << endl;


    return 0;
}

