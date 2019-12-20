// https://ac.nowcoder.com/acm/problem/14322

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 1005;

int main()
{
    int n, m, i;
    bool haveAns = true;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &m);
        vector <int> Cnt(maxn);
        vector <int> A(m);
        haveAns = true;
        for (i = 0; i < m; ++i) {
            scanf("%d", &A[i]);
            if (!haveAns) {
                continue;
            }
            if (Cnt[A[i]] != 0) {
                haveAns = false;
            } else {
                ++Cnt[A[i]];
            }
        }
        if (haveAns && is_sorted(A.begin(), A.end())) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}