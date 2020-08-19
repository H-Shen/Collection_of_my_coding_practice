// https://open.kattis.com/problems/datum
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

inline
string zeller_congruence(int year, int month, int day) {

    std::string result;

    bool flag = false;
    if (year <= 1581 || (year == 1582 && month <= 9) || (year == 1582 && month == 10 && month <= 4))
        flag = true;

    if (month == 1 || month == 2) {
        --year;
        month += 12;
    }
    int c = year / 100;
    int y = year - c * 100;
    int week = 0;

    if (!flag) {
        week = c / 4 - 2 * c + y + y / 4 + 13 * (month + 1) / 5 + day - 1;
        while (week < 0)
            week += 7;
        week %= 7;
    } else {
        week = y + y / 4 + c / 4 - 2 * c + 13 * (month + 1) / 5 + day + 2;
        while (week < 0)
            week += 7;
        week %= 7;
    }

    switch (week) {
        case 1:
            result = "Monday";
            break;
        case 2:
            result = "Tuesday";
            break;
        case 3:
            result = "Wednesday";
            break;
        case 4:
            result = "Thursday";
            break;
        case 5:
            result = "Friday";
            break;
        case 6:
            result = "Saturday";
            break;
        default:
            result = "Sunday";
            break;
    }
    return result;
}

int main() {
    int m, d;
    cin >> d >> m;
    cout << zeller_congruence(2009, m, d) << '\n';
    return 0;
}
