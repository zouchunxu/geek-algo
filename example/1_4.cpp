#include <iostream>
#include "list/list.hpp"

using namespace std;


int main() {
    List<int> list;
    list.put(1);
    list.put(2);
    list.put(3);
    list.put(4);
    list.put(5);
    list.put(6);
    list.put(7);
    list.put(8);
    list.put(9);

    ListNode<int> * n = list.centNode();

    cout << n->val << endl;


    return 0;
}