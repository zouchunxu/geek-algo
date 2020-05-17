//
// Created by 邹春旭 on 2020-05-16.
//

#include <iostream>
#include "search/Match.h"
#include <string>

using namespace std;

int main() {
    string a = "acabcab";
    string b = "cabcab";
    int m = b.size();
    int n = a.size();

    cout << Match::bm(a, n, b, m) << endl;


    return 0;
}