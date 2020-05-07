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


    return 0;
}

