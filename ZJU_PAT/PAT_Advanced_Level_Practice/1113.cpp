#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, i;
    scanf("%d", &n);
    vector<ll> A(n);

    for (auto &p : A) {
        scanf("%lld", &p);
    }
    ll gap = 0;
    ll s1, s2, mid;
    sort(A.begin(), A.end());
    if (A.size() % 2 == 0) {
        s1 = 0, s2 = 0;
        for (i = 0; i < static_cast<int>(A.size()) / 2; ++i) {
            s1 += A[i];
        }
        for (i = static_cast<int>(A.size()) / 2; i < static_cast<int>(A.size()); ++i) {
            s2 += A[i];
        }
        gap = abs(s1 - s2);
        printf("0 %lld\n", gap);
    } else {
        mid = A[A.size() / 2];
        s1 = 0, s2 = 0;
        for (i = 0; i < static_cast<int>(A.size()) / 2; ++i) {
            s1 += A[i];
        }
        for (i = static_cast<int>(A.size()) / 2 + 1; i < static_cast<int>(A.size()); ++i) {
            s2 += A[i];
        }
        gap = (std::max)(abs(s1 + mid - s2), abs(s2 + mid - s1));
        printf("1 %lld\n", gap);
    }
    return 0;
}
