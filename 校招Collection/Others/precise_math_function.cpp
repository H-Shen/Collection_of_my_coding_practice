// https://ac.nowcoder.com/acm/problem/15753
#include <bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);

int main()
{
    int n, x, t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &n, &x);
        printf("%.*f\n", x, pow(n, pi));
    }
    return 0;
}