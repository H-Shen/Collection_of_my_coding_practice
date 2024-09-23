// https://ac.nowcoder.com/acm/problem/15384

#include <iostream>
#include <string>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>

using namespace std;

int main()
{
    int n, i, j;
    scanf("%d", &n);
    vector < vector <int> > res(n);
    for (auto &&p : res)
    {
        p.resize(n);
    }

    int endVal = n * n - n + 1;
    int curVal = 1;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n - 1; ++j)
        {
            res[i][j] = curVal;
            ++curVal;
        }
        res[i][n - 1] = endVal;
        ++endVal;
    }

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n - 1; ++j)
        {
            printf("%d ", res[i][j]);
        }
        printf("%d\n", res[i][n - 1]);
    }
    return 0;
}