#include <bits/extc++.h>

using namespace std;
using ll = long long;

constexpr ll MOD = 1e6;

const int N = 10005;
ll dp[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < N; ++i) {
        dp[i] = (dp[i-1]+dp[i-2]) % MOD;
    }
    int n;
    cin >> n;
    cout << dp[n] % MOD << '\n';
    return 0;
}
