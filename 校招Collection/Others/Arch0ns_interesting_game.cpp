// https://ac.nowcoder.com/acm/problem/15686

#include <bits/stdc++.h>

using namespace std;

inline static
bool cmp(const int &a, const int &b) { return a > b; }

vector<int> A;
vector<int> B;

int main() {
    int t, n, k, i, j;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);

        vector<int>().swap(A);
        vector<int>().swap(B);
        A.resize(n);
        B.resize(n * (n - 1) / 2);

        for (auto &&p : A) {
            scanf("%d", &p);
        }
        int pos = 0;
        for (i = 0; i < n - 1; ++i) {
            for (j = i + 1; j < n; ++j) {
                B[pos++] = min(A[i], A[j]);
            }
        }
        nth_element(B.begin(), B.begin() + k - 1, B.end(), cmp);
        printf("%d\n", B[k - 1]);
    }
    return 0;
}