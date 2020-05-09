//
// Created by 邹春旭 on 2020-05-09.
//

#ifndef GEEKAL_HASHTABLE_H
#define GEEKAL_HASHTABLE_H

#include <string>

using namespace std;

class HashTable {
public:
    HashTable();
    void set(string val);
    string get(string val);
    int getHash(string val);
private:
    int size;
    string *s;
};


#endif //GEEKAL_HASHTABLE_H
