// https://ac.nowcoder.com/acm/problem/14112

#include <cstdio>
#include <cstring>

const int maxn = 1000;
char s[maxn];
long long k;

int main() {

    int T, n, cnt;
    scanf("%d", &T);
    while (T--) {
        cnt = 0;
        scanf("%d", &n);
        getchar();
        while (n--) {
            scanf("%[^0-9]16-%lld", s, &k);
            getchar();
            if (strcmp(s, "bnu") == 0) {
                ++cnt;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}