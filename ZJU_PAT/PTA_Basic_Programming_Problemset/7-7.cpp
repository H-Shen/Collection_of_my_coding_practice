#include <bits/stdc++.h>

using namespace std;

const int convert = 12;

int main() {
    string s;
    int hour, minute;
    scanf("%d:%d", &hour, &minute);

    if (hour > 12) {
        hour %= convert;
        s = "PM";
    } else if (hour == 12) {
        s = "PM";
    } else {
        s = "AM";
    }

    printf("%d:%d %s\n", hour, minute, s.c_str());
    return 0;
}