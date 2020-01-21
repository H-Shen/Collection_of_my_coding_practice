#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAXN = 25;
int A[MAXN][MAXN][MAXN];

int main() {
    int w, x, h, q, x1, y1, z1, x2, y2, z2;
    scanf("%d %d %d %d", &w, &x, &h, &q);
    while (q--) {
        scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
        for (int i = x1; i <= x2; ++i) {
            for (int j = y1; j <= y2; ++j) {
                for (int k = z1; k <= z2; ++k) {
                    A[i][j][k] = 1;
                }
            }
        }
    }
    int counter = 0;
    for (int i = 1; i <= w; ++i) {
        for (int j = 1; j <= x; ++j) {
            for (int k = 1; k <= h; ++k) {
                if (A[i][j][k] == 0) {
                    ++counter;
                }
            }
        }
    }
    printf("%d\n", counter);
    return 0;
}