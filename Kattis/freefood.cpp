// https://open.kattis.com/problems/freefood
//
#include <bits/extc++.h>

using namespace std;
constexpr int MAXN = 370;
int s[MAXN];

int main() {

    int n, left, right;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &left, &right);
        for (int i = left; i <= right; ++i) {
            s[i] = 1;
        }
    }
    printf("%lu\n", count(s, s + MAXN, 1));

    return 0;
}
