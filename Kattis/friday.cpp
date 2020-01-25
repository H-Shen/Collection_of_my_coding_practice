// https://open.kattis.com/problems/friday
//
#include <bits/extc++.h>

using namespace std;

int day;

int main() {

    int t, m, d, counter;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &d, &m);
        vector<int> A(static_cast<size_t>(m));
        for (auto &i : A) {
            scanf("%d", &i);
        }
        counter = 0;
        day = 7;
        for (const auto &i : A) {
            for (int j = 1; j <= i; ++j) {
                if (day == 5 && j == 13) {
                    ++counter;
                }
                ++day;
                if (day == 8) {
                    day = 1;
                }
            }
        }
        printf("%d\n", counter);
    }
    return 0;
}
