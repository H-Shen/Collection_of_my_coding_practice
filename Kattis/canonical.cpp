// https://open.kattis.com/problems/canonical
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>
#include <bitset>
#include <numeric>
#include <concepts>
#include <functional>
#include <unordered_set>

using namespace std;
using ll = long long;

constexpr int MAXN = 2 * 1e6 + 5;

vector<int> c;
int greedy[MAXN];
int dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    c.resize(n);
    bool canonical = true;
    for (auto& i : c) cin >> i;
    for (int i = 1, coin = 0; i < c[n - 1] + c[n - 2]; ++i) {
        if (coin + 1 < n && c[coin + 1] == i) {
            ++coin;
        }
        greedy[i] = 1 + greedy[i - c[coin]];
    }
    int coin2 = 0;
    for (int i = 1; i < c[n - 1] + c[n - 2]; ++i) {
        if (coin2 + 1 < n && c[coin2 + 1] == i) {
            ++coin2;
        }
        dp[i] = i;
        for (int j = 0; j < coin2 + 1; ++j) {
            dp[i] = min(dp[i], 1 + dp[i - c[j]]);
        }
        if (dp[i] != greedy[i]) {
            cout << "non-canonical" << '\n';
            return 0;
        }
    }
    cout << "canonical" << '\n';
    return 0;
}
