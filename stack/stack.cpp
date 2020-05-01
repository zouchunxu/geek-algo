//
// Created by 邹春旭 on 2020-05-01.
//

#include "stack.h"

using namespace std;

int isO(char c);

int getInt(const string &str, int &i);

void trim(const string &str, int &i);

int calc(const string &str) {
    Stack<int> s;
    Stack<char> o;

    for (int i = 0; i < str.length(); ++i) {
        trim(str, i);
        if (isO(str[i])) {
            o.put(str[i]);

            if (str[i] == '*' || str[i] == '/') {
                s.put(getInt(str, ++i));
                int r = s.pop();
                int l = s.pop();
                char to = o.pop();

                int res;
                switch (to) {
                    case '*':
                        res = l * r;
                        break;
                    case '/':
                    default:
                        res = l / r;
                        break;
                }
                s.put(res);
            }
        } else {
            s.put(getInt(str, i));

        }
    }


    while (!(o.isEmpty())) {
        int r = s.pop();
        int l = s.pop();
        char to = o.pop();


        int res;
        switch (to) {
            case '+':
                res = l + r;
                break;
            case '-':
            default:
                res = l - r;
                break;
        }
        s.put(res);
    }

    return s.pop();
}

int getInt(const string &str, int &i) {
    trim(str, i);
    string tmp;
    while (!isO(str[i]) && i < str.length()) {
        string ts = string(1, str[i++]);
        tmp.append(ts);
    }

    char *ptr;
    int t = strtol(tmp.c_str(), &ptr, 10);

    if (i < str.length()) {
        i--;
    }

    return t;

}

void trim(const string &str, int &i) {
    while (i < str.length() &&
           (str[i] == ' ' || str[i] == '\n' || str[i] == '\r')) {
        i++;
    }
}


int isO(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}