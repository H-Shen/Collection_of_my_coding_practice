// https://ac.nowcoder.com/acm/problem/15711

#include <bits/stdc++.h>

using namespace std;

inline
bool isLeapYear(int y) {
    if ((y % 100 != 0 && y % 4 == 0) || (y % 400 == 0))
        return true;
    return false;
}

struct Date {
    int year{}, month{}, day{};
    int notIncludeNumberFourCnt = 0;
};

string toString(const Date &a) {
    string res;
    //year
    res = res + to_string(a.year) + "-";

    //month
    if (a.month < 10) {
        res = res + "0" + to_string(a.month) + "-";
    } else {
        res = res + to_string(a.month) + "-";
    }

    //day
    if (a.day < 10) {
        res = res + "0" + to_string(a.day);
    } else {
        res = res + to_string(a.day);
    }

    return res;
}

inline
bool notIncludeNumberFour(const Date &a) {
    return (a.year % 10 != 4 && a.month != 4 && a.day % 10 != 4);
}

const unordered_set<int> monthWith31daysWithoutDec = {1, 3, 5, 7, 8, 10};
const unordered_set<int> monthWith30days = {4, 6, 9, 11};

void dateAdvance(Date &a) {
    //12 31
    if (a.month == 12 && a.day == 31) {
        ++a.year;
        a.month = 1;
        a.day = 1;
    }
        //1,3,5,7,8,10 31
    else if (monthWith31daysWithoutDec.find(a.month) != monthWith31daysWithoutDec.end() && a.day == 31) {
        ++a.month;
        a.day = 1;
    }
        //2 28/29
    else if (a.month == 2 && ((isLeapYear(a.year) && a.day == 29) || (!isLeapYear(a.year) && a.day == 28))) {
        ++a.month;
        a.day = 1;
    }
        //4,6,9,11 30
    else if (monthWith30days.find(a.month) != monthWith30days.end() && a.day == 30) {
        ++a.month;
        a.day = 1;
    }
        //other cases
    else {
        ++a.day;
    }
}

vector<Date> A;
unordered_map<string, Date> A_map;

void pre() {
    Date start;
    start.year = 1990;
    start.month = 1;
    start.day = 1;
    while (!(start.year == 2018 && start.month == 4 && start.day == 22)) {
        A.push_back(start);
        dateAdvance(start);
    }

    int notIncludeNumberFourCnt = 0;
    for (auto it = A.rbegin(); it != A.rend(); ++it) {
        if (notIncludeNumberFour(*it)) {
            ++notIncludeNumberFourCnt;
        }
        it->notIncludeNumberFourCnt = notIncludeNumberFourCnt;
        A_map[toString(*it)] = *it;
    }

}

int main() {
    pre();
    int T;
    cin >> T;
    string s;
    while (T--) {
        cin >> s;
        cout << A_map[s].notIncludeNumberFourCnt << endl;
    }
    return 0;
}