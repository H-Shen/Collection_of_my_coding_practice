#include <cstdio>

using namespace std;
using ll = long long;
constexpr ll MOD = 1000007;

int main() {

    ll n;
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &n);
        printf("%lld\n", ((1 + n) * n + n * (n - 1) / 2) % MOD);
    }

    return 0;
}