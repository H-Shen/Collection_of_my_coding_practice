// https://ac.nowcoder.com/acm/contest/395/C

#include <bits/stdc++.h>

// 0: sunday
// 1-6: monday-saturday
inline static
int ZellerCongruence(int year, int month, int day) {

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

    return week;
}

int stats[7];

int main() {

    int n;
    scanf("%d", &n);
    for (int i = 1900; i <= 1900 + n - 1; ++i) {
        for (int j = 1; j <= 12; ++j) {
            ++stats[ZellerCongruence(i, j, 13)];
        }
    }

    printf("%d %d %d %d %d %d %d\n", stats[6], stats[0], stats[1], stats[2], stats[3], stats[4], stats[5]);

    return 0;
}
