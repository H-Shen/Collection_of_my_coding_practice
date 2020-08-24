#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

inline
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// 1-7 maps Monday-Sunday
inline
int zeller_congruence(int year, int month, int day) {
    bool flag = false;
    if (year <= 1581 || (year == 1582 && month <= 9) || (year == 1582 && month == 10 && month <= 4))
        flag = true;

    if (month == 1 || month == 2) {
        --year;
        month += 12;
    }
    int c = year / 100;
    int y = year - c * 100;
    int week;

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

constexpr int MAXN = 8;
array<int, MAXN> stats;

int main() {

    fast_io();
    int n;
    cin >> n;
    for (int i = 1900; i <= 1900 + n - 1; ++i) {
        for (int j = 1; j <= 12; ++j) {
            ++stats[zeller_congruence(i, j, 13)];
        }
    }
    cout << stats[6] << ' ';
    cout << stats[0] << ' ';
    cout << stats[1] << ' ';
    cout << stats[2] << ' ';
    cout << stats[3] << ' ';
    cout << stats[4] << ' ';
    cout << stats[5] << '\n';

    return 0;
}
