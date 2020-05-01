#include <iostream>
#include "list/list.hpp"

using namespace std;



int main() {
    List<int> list;
    list.put(1);
    list.put(2);
    list.put(1);

    cout << isPalindrome(list) << endl;


    return 0;
}