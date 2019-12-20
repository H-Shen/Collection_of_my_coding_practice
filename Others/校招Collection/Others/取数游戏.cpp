// https://ac.nowcoder.com/acm/problem/14679

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 3;
int a[maxn];

inline static
bool cmp(const int &a, const int &b)
{
    return (a > b);
}

int main()
{
    int t, i;
    scanf("%d", &t);
    while (t--) {
        for (i = 0; i < maxn; ++i) {
            scanf("%d", &a[i]);
        }
        sort(begin(a), end(a), cmp);
        for (i = 0; i < maxn; ++i) {
            printf("%d", a[i]);
        }
        printf("\n");
    }
    return 0;
}