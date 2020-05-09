//
// Created by 邹春旭 on 2020-05-09.
//

#include "HashTable.h"
#include <cmath>

using namespace std;

HashTable::HashTable() {
    size = (int) pow(2, 6);
    s = new string[size];
}

void HashTable::set(string val) {
    int h = getHash(val);
    do {
        h++;
    } while (h < size && s[h] != "");

    if (h > size) {
        return;
    }

    s[h] = val;
}

string HashTable::get(string val) {
    int h = getHash(val);
    do {
        h++;
    } while (h < size && s[h] != val);

    if (val != s[h]) {
        return "";
    }

    return s[h];
}

int HashTable::getHash(string val) {
    int target = 0;
    for (int i = 0; i < val.size(); ++i) {
        target += val[i];
    }
    return (size ^ (size >> 16)) & size - 1;
}
