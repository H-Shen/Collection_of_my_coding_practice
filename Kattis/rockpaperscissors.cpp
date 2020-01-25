// https://open.kattis.com/problems/rockpaperscissors
//
#include <bits/extc++.h>

using namespace std;
constexpr int maxn = 200;
constexpr int maxChar = 11;

int n, k;
vector<int> win, lose;

int main() {

    int res = 0;
    while (~scanf("%d", &n)) {

        if (n == 0) {
            break;
        }

        if (res++) {
            printf("\n");
        }

        vector<int>().swap(win);
        win.resize(maxn);
        vector<int>().swap(lose);
        lose.resize(maxn);

        scanf("%d", &k);
        for (int i = 0; i < k * n * (n - 1) / 2; i++) {
            int a, b;
            char player1[maxChar], player2[maxChar];
            scanf("%d %s %d %s", &a, player1, &b, player2);
            if ((player1[0] == 'p' && player2[0] == 'r') || (player1[0] == 'r' && player2[0] == 's') || (player1[0] == 's' && player2[0] == 'p')) {
                ++win[a];
                ++lose[b];
            } else if ((player2[0] == 'p' && player1[0] == 'r') || (player2[0] == 'r' && player1[0] == 's') ||
                       (player2[0] == 's' && player1[0] == 'p')) {
                ++win[b];
                ++lose[a];
            }
        }
        for (int i = 1; i <= n; i++) {
            if (win[i] + lose[i]) {
                printf("%.3lf\n", 1.0 * win[i] / (win[i] + lose[i]));
            } else {
                printf("-\n");
            }
        }
    }
    return 0;
}
