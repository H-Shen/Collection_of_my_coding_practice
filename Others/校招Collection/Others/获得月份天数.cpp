// https://www.nowcoder.com/practice/13aeae34f8ed4697960f7cfc80f9f7f6
// Compiled in C++14(g++5.4)

#include <bits/stdc++.h>

using namespace std;

int A[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int main() {

    int year, month;
    int is_leap_year;
    while (~scanf("%d %d", &year, &month)) {
        is_leap_year = ((year % 4 == 0 && year % 100 != 0) || (year % 400) == 0);
        if (month == 2) {
            printf("%d\n", A[month] + is_leap_year);
        } else {
            printf("%d\n", A[month]);
        }
    }

    return 0;
}