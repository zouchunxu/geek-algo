//
// Created by 邹春旭 on 2020-05-07.
//

#ifndef GEEKAL_BINARYSEARCH_H
#define GEEKAL_BINARYSEARCH_H


class Search {
public:
    static int binarySearch(const int *a, int val, int count);

    static int binarySearchFirst(const int *a, int val, int count);
    static int binarySearchLessFirst(const int *a, int val, int count);
    static int binarySearchLast(const int *a, int val, int count);
};


#endif //GEEKAL_BINARYSEARCH_H
