// https://ac.nowcoder.com/acm/problem/15441

#include <cstdio>

using namespace std;
using ll = long long;

int main()
{
    int T;
    ll n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld", &n);
        if (n % 2 == 0)
        {
            printf("%lld\n", n * n / 4);
        }
        else
        {
            printf("%lld\n", (n * n - 1) / 4);
        }
    }
    return 0;
}