#include <bits/extc++.h>

using namespace std;
using ll = long long;

constexpr int MAXN = 505;
constexpr int INF = 0x3f3f3f3f;

int GCD[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    memset(GCD, 0x3f, sizeof GCD);
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        int g = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = i+1; j <= n; ++j) {
                if (GCD[i][j] == INF) {
                    GCD[i][j] = __gcd(i, j);
                }
                g += GCD[i][j];
            }
        }
        cout << g << '\n';
    }
    return 0;
}