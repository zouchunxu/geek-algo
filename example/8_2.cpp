//
// Created by 邹春旭 on 2020-05-16.
//

#include <iostream>
#include "search/Match.h"
#include <string>

using namespace std;

int main() {
    string b = "cabcab";
    int m = b.size();
    int suffix[m];
    bool prefix[m];

    Match::generateGS(b, m, suffix, prefix);

    for (int i = 0; i < m; ++i) {
        cout << suffix[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < m; ++i) {
        cout << prefix[i] << " ";
    }
    cout << endl;


    return 0;
}