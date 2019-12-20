// https://www.nowcoder.com/practice/cc6ad889f95c49c08da1b338dd2e07ab

#include <iostream>

using namespace std;

inline
int isLeapYear(int y) {
    if ((y % 100 != 0 && y % 4 == 0) || (y % 400 == 0))
        return 1;
    return 0;
}

inline
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

    int y, m, d;
    cin >> y >> m >> d;
    cout << days(y, m, d) << endl;

    return 0;
}