#include <iostream>
#include "list/list.hpp"

using namespace std;

int main() {
    List<int> l;

    l.put(1);
    l.put(2);

//    l.put(1);

    l.put(2);
    l.put(1);

//    l.set(0, 10);

    cout << isPalindrome(l) << endl;



    return 0;
}
