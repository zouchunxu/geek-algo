//
// Created by 邹春旭 on 2020-05-15.
//

#include "Match.h"

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
