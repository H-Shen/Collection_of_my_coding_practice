#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace EulerPrimeSieve {

    const int MAXN = 1000005;
    int prime[MAXN] = {0};
    int num_prime = 0;
    bool isNotPrime[MAXN] = {true, true};

    // Generate the prime table from 1 to MAXN
    inline static
    void init() {
        for (int i = 2; i < MAXN; i++) {
            if (!isNotPrime[i])
                prime[num_prime++] = i;
            for (int j = 0; j < num_prime && i * prime[j] < MAXN; j++) {
                isNotPrime[i * prime[j]] = true;
                if (!(i % prime[j]))
                    break;
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    EulerPrimeSieve::init();
    int n;
    cin >> n;
    int j;
    for (int i = 3; i <= n; ++i) {
        j = n - i;
        if (EulerPrimeSieve::isNotPrime[i] && EulerPrimeSieve::isNotPrime[j]) {
            cout << i << ' ' << j << '\n';
            return 0;
        }
    }

    return 0;
}
