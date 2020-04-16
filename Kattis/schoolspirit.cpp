// https://open.kattis.com/problems/schoolspirit
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 55;
double coeff[MAXN];

double solve(const vector<double> &A) {
    double sum = 0;
    int n = static_cast<int>(A.size());
    for (int i = 0; i < n; ++i) {
        sum += A.at(i) * coeff[i];
    }
    sum /= 5.0;
    return sum;
}

int main() {

    coeff[0] = 1.0;
    coeff[1] = 4.0 / 5.0;
    for (int i = 2; i <= 50; ++i) {
        coeff[i] = coeff[i - 1] * 4.0 / 5.0;
    }

    int n;
    scanf("%d", &n);
    vector<double> A(n);
    for (auto &i : A) {
        scanf("%lf", &i);
    }
    vector<double> G;
    for (int i = 0; i < n; ++i) {
        auto p = A;
        p.erase(p.begin() + i);
        G.emplace_back(solve(p));
    }
    printf("%.6lf\n", solve(A));
    printf("%.6lf\n", accumulate(G.begin(), G.end(), 0.0) / (int)(G.size()));
    return 0;
}
