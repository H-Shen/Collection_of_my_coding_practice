#include <bits/stdc++.h>

using namespace std;

const int GAP = 48;

int main() {

    string s;
    cin >> s;
    bool isNegative = false, isOven = false;

    int i = 0, len = s.size(), cnt = 0;
    int resLen = len;
    if (s.at(0) == '-') {
        isNegative = true;
        ++i;
        --resLen;
    }
    for (; i < len - 1; ++i) {
        if (s.at(i) == '2') {
            ++cnt;
        }
    }
    if ((s.at(len - 1) - GAP) % 2 == 0) {
        if (s.at(len - 1) == '2') {
            ++cnt;
        }
        isOven = true;
    }
    double res = (double) cnt / (double) resLen * 100.0;
    if (isNegative) {
        res *= 1.5;
    }
    if (isOven) {

        res *= 2.0;
    }
    printf("%.2f%%\n", res);
    return 0;
}