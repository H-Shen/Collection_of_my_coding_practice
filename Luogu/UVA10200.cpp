#include <cstdio>
#include <numeric>

typedef long long ll;

const int MAXN = 10000;
constexpr double EPS = 1e-6;

int is_prime[MAXN + 5];
int prefix[MAXN + 5];

int main() {

    auto f = [](ll n) {
        if (n <= 1) {
            return false;
        }
        for (ll i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    };

    for (ll i = 0; i <= MAXN; ++i) {
        if (f(i * i + i + 41)) {
            is_prime[i] = 1;
        }
    }
    std::partial_sum(is_prime, is_prime + MAXN + 5, prefix);

    int a, b, c, total;
    while (~scanf("%d %d", &a, &b)) {
        total = b - a + 1;
        if (a == b) {
            c = is_prime[b];
        } else if (a == 0) {
            c = prefix[b];
        } else {
            c = prefix[b] - prefix[a - 1];
        }
        printf("%.2lf\n", EPS + c * 100.0 / total);
    }

    return 0;
}
