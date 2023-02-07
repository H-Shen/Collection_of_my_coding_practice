// https://open.kattis.com/problems/tight 

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <iomanip>

using namespace std;
using ll = long long;

constexpr int MAXN = 105;
constexpr int MAXK = 10;

double dp[MAXN][MAXK];
int n, k;

double solve(int i, int j) {
    if (dp[i][j] != -1.0) {
        return dp[i][j];
    }
    dp[i][j] = solve(i - 1, j);
    if (j > 0) {
        dp[i][j] += solve(i - 1, j - 1);
    }
    if (j < k) {
        dp[i][j] += solve(i - 1, j + 1);
    }
    return dp[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (cin >> k >> n) {
        for (int i = 0; i < MAXN; ++i) {
            for (int j = 0; j < MAXK; ++j) {
                dp[i][j] = -1.0;
            }
        }
        for (int i = 0; i < MAXK; ++i) {
            dp[0][i] = 0;
        }
        for (int i = 0; i < MAXK; ++i) {
            dp[1][i] = 1;
        }
        double sum = 0;
        for (int i = 0; i <= k; ++i) {
            sum += solve(n, i);
        }
        double tot = pow(k + 1, n);
        cout << fixed << setprecision(9) << sum * 100.0 / tot << '\n';
    }
    return 0;
}
