#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAXN = 100;
array<int, MAXN> stats;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    for (const auto &i : s) {
        ++stats[i];
    }
    int max_val = -1;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        max_val = max(max_val, stats[ch]);
    }
    cout << max_val << '\n';

    return 0;
}
