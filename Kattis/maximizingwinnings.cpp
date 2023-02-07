// https://open.kattis.com/problems/maximizingwinnings

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int GAMES = 55;
constexpr int TURNS = 5005;

int dp1[TURNS][GAMES];
int dp2[TURNS][GAMES];
int w[GAMES][GAMES];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        memset(dp1, 0, sizeof dp1);
        memset(dp2, 0, sizeof dp2);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> w[i][j];
            }
        }
        cin >> m;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp1[i][j] = dp1[i-1][0] + w[j][0];
                dp2[i][j] = dp2[i-1][0] + w[j][0];
                for (int k = 1; k < n; ++k) {
                    dp1[i][j] = min(dp1[i][j], w[j][k] + dp1[i-1][k]);
                    dp2[i][j] = max(dp2[i][j], w[j][k] + dp2[i-1][k]);
                }
            }
        }
        cout << dp2[m][0] << ' ' << dp1[m][0] << '\n';
    }
    return 0;
}