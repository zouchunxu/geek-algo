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

int Match::bm(string a, int n, string b, int m) {
    int bc[255];
    generateBC(b, m, bc);
    int suffix[m];
    bool prefix[m];
    generateGS(b, m, suffix, prefix);
    int i = 0;
    while (i <= n - m) {
        int j;
        for (j = m - 1; j >= 0; j--) {
            if (a[i + j] != b[j]) break;
        }
        if (j < 0) {
            return i;
        }
        int x = j - bc[(int) a[i + j]];
        int y = 0;
        if (j < m - 1) {
            y = moveByGS(j, m, suffix, prefix);
        }
        i += max(x, y);
    }

    return -1;
}

int Match::moveByGS(int j, int m, int *suffix, bool *prefix) {
    int k = m - 1 - j;
    if (suffix[k] != -1) return j - suffix[k] + 1;
    for (int r = j + 2; r <= m - 1; ++r) {
        if (prefix[m - r]) return r;
    }
    return m;
}

void Match::generateBC(string b, int m, int *bc) {
    for (int i = 0; i < 256; ++i) {
        bc[i] = -1;
    }

    for (int j = 0; j < m; ++j) {
        bc[(int) b[j]] = j;
    }
}

void Match::generateGS(string b, int m, int *suffix, bool *prefix) {
    for (int i = 0; i < m; ++i) {
        suffix[i] = -1;
        prefix[i] = false;
    }

    for (int i = 0; i < m - 1; ++i) {

        int j = i;
        int k = 0;
        while (j >= 0 && b[j] == b[m - 1 - k]) {
            --j;
            ++k;
            suffix[k] = j + 1;
        }

        if (j == -1) {
            prefix[k] = true;
        }

    }
}
