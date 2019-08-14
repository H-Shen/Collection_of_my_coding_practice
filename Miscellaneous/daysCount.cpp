#include <bits/stdc++.h>

using namespace std;

// Return 1 if 'y' is leap, otherwise 0.
inline static
int isLeapYear(const int &y) {
    if ((y % 100 != 0 && y % 4 == 0) || (y % 400 == 0))
        return 1;
    return 0;
}

// Return the number from the first day of the given year to the date given. (判断是一年的第几天)
inline static
int days(int year, int month, int day) {
    int isleap = isLeapYear(year);
    int total = 0;
    switch (month - 1) {
        case 12:
            total += 31;
        case 11:
            total += 30;
        case 10:
            total += 31;
        case 9:
            total += 30;
        case 8:
            total += 31;
        case 7:
            total += 31;
        case 6:
            total += 30;
        case 5:
            total += 31;
        case 4:
            total += 30;
        case 3:
            total += 31;
        case 2:
            total += 28 + isleap;
        case 1:
            total += 31;
            total += day;
            break;
        case 0:
            total = day;
            break;
    }
    return total;
}

int main() {
    assert(days(1900, 1, 1) == 1);
    assert(days(1900, 1, 2) == 2);
    assert(days(1600, 3, 28) != 2);
    return 0;
}