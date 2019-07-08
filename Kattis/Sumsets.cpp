#include <cstdio>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;
const int maxn = 4005;
const ll minVal = -536870920;

ll A[maxn];
unordered_map < int, pair<int, int> > ab;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &A[i]);
    }
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            ab[A[i] + A[j]] = make_pair(A[i], A[j]);
        }
    }
    ll max_d = minVal;
    ll c, d, a, b;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            d = A[i];
            c = A[j];
            if (ab.find(d - c) != ab.end())
            {
                a = ab[d - c].first;
                b = ab[d - c].second;
                if (d != a && d != b && c != a && c != b)
                {
                    max_d = max(max_d, d);
                }
            }
            d = A[j];
            c = A[i];
            if (ab.find(d - c) != ab.end())
            {
                a = ab[d - c].first;
                b = ab[d - c].second;
                if (d != a && d != b && c != a && c != b)
                {
                    max_d = max(max_d, d);
                }
            }
        }
    }
    if (max_d == minVal) printf("no solution\n");
    else printf("%lld\n", max_d);
    return 0;
}

