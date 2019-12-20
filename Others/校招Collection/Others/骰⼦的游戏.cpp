// https://ac.nowcoder.com/acm/problem/14525

#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 6, maxcase = 36;

int main()
{
    int t, i, j, pa, pb, cnt;
    scanf("%d", &t);
    while (t--) {
        vector <int> A(maxn), B(maxn);
        for (i = 0; i < maxn; ++i) {
            scanf("%d", &A[i]);
        }
        for (i = 0; i < maxn; ++i) {
            scanf("%d", &B[i]);
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        pa = 0;
        pb = 0;
        for (i = 0; i < maxn; ++i) {
            for (j = 0; j < maxn; ++j) {
                if (A[i] <= B[j]) {
                    break;
                } else {
                    ++pa;
                }
            }
        }

        for (i = 0; i < maxn; ++i) {
            for (j = 0; j < maxn; ++j) {
                if (B[i] <= A[j]) {
                    break;
                } else {
                    ++pb;
                }
            }
        }
        if (pa > pb) {
            puts("Alice");
        } else if (pa < pb) {
            puts("Bob");
        } else {
            puts("Tie");
        }
    }
    return 0;
}