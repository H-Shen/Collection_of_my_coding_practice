// https://open.kattis.com/problems/theplank

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 26;
ll dp[MAXN];

// dp[0] = 0
// dp[1] = 1
// dp[2] = 2
// dp[3] = 4 (111 3 12 21)
// dp[n] = dp[n-1]+dp[n-2]+dp[n-3]


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= 24; ++i) {
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }
    int n;
    cin >> n;
    cout << dp[n] << '\n';

    return 0;
}
