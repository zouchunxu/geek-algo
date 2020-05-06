//
// Created by 邹春旭 on 2020-05-05.
//

#ifndef GEEKAL_ARRAYSORT_H
#define GEEKAL_ARRAYSORT_H


class ArraySort {
public:
    static void mergeSort(int *a,int count);
    static void quickSort(int *a,int count);

private:
    static void mergeSortC(int *a, int s, int p);
    static void quickSortC(int *a, int s, int p);
};


#endif //GEEKAL_ARRAYSORT_H
