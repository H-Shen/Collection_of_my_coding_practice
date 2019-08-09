// https://ac.nowcoder.com/acm/problem/15128

#include <bits/stdc++.h>

using namespace std;
constexpr int N = 8;

int main()
{
    vector <int> A(N);
    iota(A.begin(), A.end(), 1);
    int i;

    do {
        for (i = 0; i < N - 1; ++i) {
            printf("%d ", A[i]);
        }
        printf("%d\n", A[N - 1]);
    } while (next_permutation(A.begin(), A.end()));

    return 0;
}