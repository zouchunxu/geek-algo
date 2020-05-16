//
// Created by 邹春旭 on 2020-05-15.
//

#ifndef GEEKAL_MATCH_H
#define GEEKAL_MATCH_H

#include <string>

using namespace std;

class Match {
public:
    static bool bfMatch(string s, string sub);

    static bool rkMatch(string s, string sub);

    static int bm(string a, int n, string b, int m);

    static int moveByGS(int j, int m, int suffix[], bool prefix[]);

    static void generateBC(string b, int m, int bc[]);

    static void generateGS(string b, int m, int suffix[], bool prefix[]);

};


#endif //GEEKAL_MATCH_H
