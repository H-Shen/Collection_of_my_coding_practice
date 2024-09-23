// https://ac.nowcoder.com/acm/problem/14339

#include <cstdio>

using namespace std;
const int maxn = 120;

int main()
{
    int t, W, T, n;
    while (~scanf("%d", &t)) {
        while (t--) {
            scanf("%d %d", &W, &T);
            n = (W - maxn) / T;
            if (W - n * T > maxn) {
                ++n;
            }
            if (n < 0) {
                n = 0;
            }
            printf("%d\n", n);
        }
    }
    return 0;
}