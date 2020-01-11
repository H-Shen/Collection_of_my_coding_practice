// https://open.kattis.com/problems/averageseasy
//
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr double EPS = 1e-6;

inline static
int sgn(const double &a) {
    if (a > EPS) {
        return 1;
    }
    if (a > -EPS) {
        return 0;
    }
    return -1;
}

int main() {

    int T;
    int n;
    int m;
    ll sumA;
    ll sumB;
    double avgA;
    double avgB;
    double avgA_;
    double avgB_;
    int counter;

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        vector<ll> A(n);
        vector<ll> B(m);
        for (auto &i : A) {
            scanf("%lld", &i);
        }
        for (auto &i : B) {
            scanf("%lld", &i);
        }
        sumA = accumulate(A.begin(), A.end(), (ll) 0);
        sumB = accumulate(B.begin(), B.end(), (ll) 0);
        avgA = sumA * 1.0 / n;
        avgB = sumB * 1.0 / m;
        counter = 0;
        for (const auto &i : A) {
            avgA_ = static_cast<double>(sumA - i) / (n - 1);
            avgB_ = static_cast<double>(sumB + i) / (m + 1);
            if (sgn(avgA_ - avgA) > 0 && sgn(avgB_ - avgB) > 0) {
                ++counter;
            }
        }
        printf("%d\n", counter);
    }


    return 0;
}
