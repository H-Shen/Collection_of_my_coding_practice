#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr ll INF = 0x3f3f3f3f;
constexpr int MAXN = 25;
ll w[MAXN][MAXN][MAXN];

ll solve(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    if (a > 20 || b > 20 || c > 20) {
        return solve(20, 20, 20);
    }
    if (w[a][b][c] != INF) {
        return w[a][b][c];
    }
    if (a < b && b < c) {
        w[a][b][c] = solve(a, b, c - 1) + solve(a, b - 1, c - 1) - solve(a, b - 1, c);
    } else {
        w[a][b][c] = solve(a-1,b,c)+solve(a-1,b-1,c)+solve(a-1,b,c-1)-solve(a-1,b-1,c-1);
    }
    return w[a][b][c];
}

int main() {

    // pre
    for (int i = 1; i <= 20; ++i) {
        for (int j = 1; j <= 20; ++j) {
            for (int k = 1; k <= 20; ++k) {
                w[i][j][k] = INF;
            }
        }
    }

    int a, b, c;
    while (true) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1) break;
        printf("w(%d, %d, %d) = %lld\n", a, b, c, solve(a, b, c));
    }

    return 0;
}