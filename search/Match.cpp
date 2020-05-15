//
// Created by 邹春旭 on 2020-05-15.
//

#include "Match.h"
#include <cmath>
#include <iostream>

using namespace std;

bool Match::bfMatch(string s, string sub) {

    int start = 0;
    while (start < s.size()) {
        for (int i = 0; i < sub.size(); ++i) {
            if (start + i >= s.size()) {
                return false;
            }
            if (s[start + i] != sub[i]) {
                break;
            }

            if (i + 1 == sub.size()) {
                return true;
            }
        }
        start++;
    }


    return false;
}

bool Match::rkMatch(string s, string sub) {

    int ssize = s.size();
    int subSize = sub.size();


    int subHash = 0;
    for (int i = subSize; i > 0; --i) {
        subHash += (sub[subSize - i] - 97) * pow(26, i - 1);
    }


    for (int i = 0; i + subSize < ssize; ++i) {
        int hash = 0;
        for (int j = subSize; j > 0; --j) {
            hash += (s[i + subSize - j] - 97) * pow(26, j - 1);
        }

        if (subHash == hash) {
            return true;
        }
    }

    return false;
}
