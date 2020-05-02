//
// Created by 邹春旭 on 2020-05-02.
//

#include "list/lrucache.h"
#include <iostream>

using namespace std;

int main() {

    LRUCache<int> lruCache(2);


    lruCache.put("a", 1);
    lruCache.put("b", 2);
    lruCache.put("a", 3);

//    lruCache.del("a");

    cout << *(lruCache.get("a")) << endl;


    return 0;
}
