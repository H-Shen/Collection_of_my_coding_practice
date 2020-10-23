#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 10005;
constexpr int N = 10;
array<array<int, N>, MAXN> stats;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    stats.at(1).at(1) = 1;
    int copy;
    for (int i = 2; i < MAXN; ++i) {
        copy = i;
        stats.at(i) = stats.at(i - 1);
        while (copy > 0) {
            ++stats.at(i).at(copy % 10);
            copy /= 10;
        }
    }
    int n, val;
    cin >> n;
    while (n--) {
        cin >> val;
        cout << stats.at(val).at(0);
        for (int i = 1; i <= 9; ++i) {
            cout << ' ' << stats.at(val).at(i);
        }
        cout << '\n';
    }
    return 0;
}