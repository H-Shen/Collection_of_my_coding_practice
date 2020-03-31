// https://open.kattis.com/problems/tgif
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

unordered_map<string, int> A = {
        {"JAN", 1},
        {"FEB", 2},
        {"MAR", 3},
        {"APR", 4},
        {"MAY", 5},
        {"JUN", 6},
        {"JUL", 7},
        {"AUG", 8},
        {"SEP", 9},
        {"OCT", 10},
        {"NOV", 11},
        {"DEC", 12}
};

unordered_map<string, int> Week = {
        {"MON", 0},
        {"TUE", 1},
        {"WED", 2},
        {"THU", 3},
        {"FRI", 4},
        {"SAT", 5},
        {"SUN", 6}
};

vector<int> days = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int main() {

    int month, day, week;
    string a, b;
    cin >> day >> a >> b;
    month = A[a];
    week = Week[b];

    int days_count;
    bool case1 = false;
    bool case2 = false;
    // Case 1: not a leap year
    days_count = 0;
    for (int i = 0; i < month; ++i) {
        days_count += days.at(i);
    }
    days_count += day;
    --days_count;
    for (int i = 0; i < days_count; ++i) {
        ++week;
        if (week > 6) {
            week = 0;
        }
    }
    if (week == 4) {
        case1 = true;
    }

    // Case 2: a leap year
    days_count = 0;
    for (int i = 0; i < month; ++i) {
        days_count += days.at(i);
        if (i == 2) {
            ++days_count;
        }
    }
    days_count += day;
    --days_count;
    week = Week[b];
    for (int i = 0; i < days_count; ++i) {
        ++week;
        if (week > 6) {
            week = 0;
        }
    }
    if (week == 4) {
        case2 = true;
    }
    if (case1 && case2) {
        cout << "TGIF" << endl;
    } else if (!case1 && !case2) {
        cout << ":(" << endl;
    } else {
        cout << "not sure" << endl;
    }

    return 0;
}
