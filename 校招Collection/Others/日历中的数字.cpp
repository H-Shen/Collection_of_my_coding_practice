// https://ac.nowcoder.com/acm/problem/13584

#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 12;
static int days[maxn] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline static
int leap_year(const int y)
{
    return ((y % 100 != 0 && y % 4 == 0) || (y % 400 == 0));
}

int main()
{
    int y, m, d, i, cnt;
    char d_ch;
    string date, date_copy;
    while (~scanf("%d %d %d", &y, &m, &d)) {

        if (leap_year(y)) {
            days[1] = 29;
        } else {
            days[1] = 28;
        }

        date = to_string(y);

        if (m < 10) {
            date = date + "0" + to_string(m);
        } else {
            date = date + to_string(m);
        }

        cnt = 0;
        d_ch = d + '0';
        for (i = 1; i <= days[m - 1]; ++i) {
            if (i < 10) {
                date_copy = date + "0" + to_string(i);
            } else {
                date_copy = date + to_string(i);
            }
            for (const auto &p : date_copy) {
                if (p == d_ch) {
                    ++cnt;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}