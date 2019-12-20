// https://ac.nowcoder.com/acm/problem/14333
#include <bits/stdc++.h>

using namespace std;
constexpr double eps = 1e-6;

bool cmp(const int &a, const int &b)
{
    return (a > b);
}

int main()
{
    int n, m, k, i, cnt;


    while (~scanf("%d %d %d", &n, &m, &k)) {

        cnt = 0;
        vector <int> A(n);
        for (i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
        }

        if (m <= k) {
            cnt = 0;
        } else {
            sort(A.begin(), A.end(), cmp);
            m -= k;
            i = 0;
            while (1) {
                if (m > 0 && cnt >= n) {
                    cnt = -1;
                    break;
                } else if (m <= 0) {
                    break;
                }
                ++cnt;
                m = m - A[i] + 1;
                ++i;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}