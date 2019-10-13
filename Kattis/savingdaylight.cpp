// https://open.kattis.com/problems/savingdaylight
//
#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 20;
char s[MAXN];

int main() {

    int day, year, h0, m0, h1, m1, diff;
    while (~scanf("%s %d %d %d:%d %d:%d", s, &day, &year, &h0, &m0, &h1, &m1)) {
        int total0 = h0 * 60 + m0;
        int total1 = h1 * 60 + m1;
        if (total0 < total1) {
            diff = total1 - total0;
        } else {
            diff = 24 * 60 + (total1 - total0);
        }
        int hour = diff / 60;
        int min = diff % 60;
        printf("%s %d %d %d hours %d minutes\n", s, day, year, hour, min);
    }

    return 0;
}
