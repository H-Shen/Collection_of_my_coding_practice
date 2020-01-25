// https://open.kattis.com/problems/dreamer
//
#include <bits/extc++.h>

using namespace std;

constexpr int MAXN = 12;
static int daysForNonLeapYear[MAXN] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static int daysForLeapYear[MAXN] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

constexpr int MAX_STRING_LENGTH = 5;
char dayCStr[MAX_STRING_LENGTH];
char monthCStr[MAX_STRING_LENGTH];
char yearCStr[MAX_STRING_LENGTH];

inline static
bool isLeapYear(const int &y) {
    return ((y % 100 != 0 && y % 4 == 0) || (y % 400 == 0));
}

inline static
bool isValid(const string &dayStr, const string &monthStr, const string &yearStr) {

    int day = stoi(dayStr);
    int month = stoi(monthStr);
    int year = stoi(yearStr);

    // Must be before 1.1.2000
    if (year < 2000) {
        return false;
    }
    // Month must be 1 - 12
    if (month < 1 || month > 12) {
        return false;
    }
    if (isLeapYear(year)) {
        if (day < 1 || day > daysForLeapYear[month - 1]) {
            return false;
        }
    } else {
        if (day < 1 || day > daysForNonLeapYear[month - 1]) {
            return false;
        }
    }
    return true;
}

struct Date {
    string dayStr, monthStr, yearStr;

    Date(string dayStr, string monthStr, string yearStr) :
            dayStr(std::move(dayStr)), monthStr(std::move(monthStr)), yearStr(std::move(yearStr)) {}

    Date() : Date("", "", "") {}
};

inline static
int threeWayComparator(const Date &lhs, const Date &rhs) {
    int lhsYear = stoi(lhs.yearStr);
    int rhsYear = stoi(rhs.yearStr);
    if (lhsYear == rhsYear) {
        int lhsMonth = stoi(lhs.monthStr);
        int rhsMonth = stoi(rhs.monthStr);
        if (lhsMonth == rhsMonth) {
            int lhsDay = stoi(lhs.dayStr);
            int rhsDay = stoi(rhs.dayStr);
            if (lhsDay == rhsDay) {
                return 0;
            } else if (lhsDay < rhsDay) {
                return -1;
            }
            return 1;
        } else if (lhsMonth < rhsMonth) {
            return -1;
        }
        return 1;
    } else if (lhsYear < rhsYear) {
        return -1;
    }
    return 1;
}

inline static
void perm(string s) {
    sort(s.begin(), s.end());
    string day, month, year;
    Date earliestDate;
    int counter = 0;
    do {
        day = s.substr(0, 2);
        month = s.substr(2, 2);
        year = s.substr(4);
        if (isValid(day, month, year)) {
            Date currentDate = Date(day, month, year);
            if (counter == 0) {
                earliestDate = currentDate;
            } else {
                if (threeWayComparator(currentDate, earliestDate) == -1) {
                    earliestDate = currentDate;
                }
            }
            ++counter;
        }
    } while (next_permutation(s.begin(), s.end()));

    // output
    if (counter == 0) {
        printf("0\n");
    } else {
        printf("%d %s %s %s\n",
               counter,
               earliestDate.dayStr.c_str(),
               earliestDate.monthStr.c_str(),
               earliestDate.yearStr.c_str());
    }
}

int main() {

    int n;
    string date;
    scanf("%d", &n);
    while (n--) {
        scanf("%s %s %s", dayCStr, monthCStr, yearCStr);
        date = string(dayCStr) + monthCStr + yearCStr;
        perm(date);
    }

    return 0;
}
