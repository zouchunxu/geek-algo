//
// Created by 邹春旭 on 2020-05-08.
//

#include <iostream>
#include "list/HashTable.h"
#include <string>

using namespace std;

int main() {

    HashTable hashTable;

    hashTable.set("a");
    hashTable.set("b");

    cout << hashTable.get("a") << endl;
    cout << hashTable.get("b") << endl;


    return 0;
}