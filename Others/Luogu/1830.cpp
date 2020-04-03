#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr int MAXN = 105;

struct Node {
    int val;
    int round;
};

Node A[MAXN][MAXN];

int main() {

    int n, m, x, y, x1, x2, y1, y2;
    scanf("%d %d %d %d", &n, &m, &x, &y);
    for (int round = 1; round <= x; ++round) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for (int i = x1; i <= x2; ++i) {
            for (int j = y1; j <= y2; ++j) {
                ++A[j][i].val;
                A[j][i].round = round;
            }
        }
    }
    while (y--) {
        scanf("%d %d", &x1, &y1);
        if (A[y1][x1].val == 0) {
            printf("N\n");
        } else {
            printf("Y %d %d\n", A[y1][x1].val, A[y1][x1].round);
        }
    }
    return 0;
}
