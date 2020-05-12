//
// Created by 邹春旭 on 2020-05-11.
//
#include <iostream>
#include "tree/SearchTree.h"

using namespace std;

int main() {
    SearchTree searchTree;

    searchTree.insert(1);
    searchTree.insert(2);
    searchTree.insert(3);
    searchTree.insert(6);
    searchTree.del(6);


    searchTree.print();

//    cout << searchTree.get(1) << endl;
//    cout << searchTree.get(6) << endl;
//    cout << searchTree.get(7) << endl;
    return 0;
}