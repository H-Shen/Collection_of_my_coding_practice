// https://ac.nowcoder.com/acm/problem/14652

#include <cstdio>

using namespace std;
using ll = long long;

int main()
{
    int n;
    scanf("%d", &n);
    ll a, b;
    while (n--) {
        scanf("%llu %llu", &a, &b);
        printf("%llu\n", b - a);
    }
    return 0;
}