#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr double EPS = 1e-7;
int sgn(const double &x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

int main() {

    int x;
    ll m, n;
    // input
    scanf("%d %lld %lld", &x, &m, &n);

    // 1st problem
    set<double> s;
    s.insert(x);
    s.insert((180.0 - x) / 2.0);
    s.insert(x / 2.0);
    s.insert(180.0 - 2.0 * x);
    int temp;
    bool first_item = true;
    for (const auto &i : s) {
        if (first_item) {
            first_item = false;
        } else {
            printf(" ");
        }
        temp = i;
        if (sgn(temp * 1.0 - i) == 0) {
            printf("%d", temp);
        } else {
            printf("%.1lf", i);
        }
    }
    printf("\n");

    // 2nd problem
    set<double> s_;
    s_.insert(sqrt(m * m + n * n));
    if (m < n) {
        swap(m, n);
        s_.insert(sqrt(m * m - n * n));
    }
    first_item = true;
    for (const auto &i : s_) {
        if (first_item) {
            first_item = false;
        } else {
            printf(" ");
        }
        printf("%.5lf", i);
    }
    printf("\n");
    return 0;
}