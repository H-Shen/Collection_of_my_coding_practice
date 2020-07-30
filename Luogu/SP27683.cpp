#include <vector>
#include <cstdio>
#include <numeric>

int main() {

    using namespace std;
    using ll = long long;
    int n;
    scanf("%d", &n);
    vector<ll> A(n);
    vector<ll> B(n);
    for (auto &i : A) scanf("%lld", &i);
    partial_sum(A.begin(), A.end(), B.begin());
    int q, a, b;
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &a, &b);
        --a;
        --b;
        if (a == 0) {
            printf("%lld\n", B.at(b));
        } else {
            printf("%lld\n", B.at(b) - B.at(a - 1));
        }
    }

    return 0;
}