//
// Created by 邹春旭 on 2020-05-05.
//

#ifndef GEEKAL_ARRAYSORT_H
#define GEEKAL_ARRAYSORT_H

#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class ArraySort {
public:
    static void mergeSort(int *a, int count);

    static void quickSort(int *a, int count);

    template<typename T>
    static void bucketSort(T *a, int count, int (*call)(T a));

private:
    static void mergeSortC(int *a, int s, int p);

    static void quickSortC(int *a, int s, int p);
};


template<typename T>
void ArraySort::bucketSort(T *a, int count, int (*call)(T)) {
    unordered_map<int, vector<int>> halt;

    for (int i = 0; i < count; ++i) {
        int key = call(a[i]);
        halt[key].push_back(a[i]);
    }

    int k = 0;
    for (int j = 0; j < halt.size(); ++j) {
        sort(halt[j].begin(), halt[j].end());
        for (int i = 0; i < halt[j].size(); ++i) {
            a[k++] = halt[j][i];
        }
    }

}

#endif //GEEKAL_ARRAYSORT_H
