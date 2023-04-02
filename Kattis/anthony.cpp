// https://open.kattis.com/problems/anthony
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <iomanip>

using namespace std;
using ll = long long;

constexpr int MAXN = 1005;
constexpr int MAXM = 1005;

double probability[MAXN + MAXM - 1];
double dp[MAXN][MAXM];
int n, m;

double solve(int a, int b) {
    if (b == 0) {
        return 1.0;
    }
    else if (a == 0) {
        return 0.0;
    }
    else if (dp[a][b] != -1.0) {
        return dp[a][b];
    }
    int tot = (n + m) - (a + b);
    if (tot >= n + m) {
        dp[a][b] = 0.0;
        return dp[a][b];
    }
    dp[a][b] = solve(a - 1, b) * (1 - probability[tot]) + solve(a, b - 1) * probability[tot];
    return dp[a][b];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n + m - 1; ++i) {
        cin >> probability[i];
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            dp[i][j] = -1.0;
        }
    }
    cout << fixed << setprecision(7) << solve(n, m) << '\n';
    return 0;
}


