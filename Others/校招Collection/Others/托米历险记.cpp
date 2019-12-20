// https://ac.nowcoder.com/acm/problem/16607

#include <bits/stdc++.h>

using namespace std;
constexpr int maxn = 100005;
int A[2]; //25 50
int L[maxn];

int main() {
    int n, i;
    scanf("%d", &n);

    for (i = 0; i < n; ++i) {
        scanf("%d", &L[i]);
    }

    A[0] = 0;
    A[1] = 0;
    bool haveAns = true;

    for (i = 0; i < n; ++i) {
        if (L[i] == 25) {
            ++A[0];
        } else if (L[i] == 50) {
            if (A[0] == 0) {
                haveAns = false;
                break;
            } else {
                --A[0];
                ++A[1];
            }
        } else {
            if (A[1] >= 1 && A[0] >= 1) {
                --A[1];
                --A[0];
            } else if (A[0] >= 3) {
                A[0] -= 3;
            } else {
                haveAns = false;
                break;
            }
        }
    }

    if (haveAns) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}