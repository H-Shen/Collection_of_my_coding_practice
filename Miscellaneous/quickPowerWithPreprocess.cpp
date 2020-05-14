#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr ll MOD = 1000000007;

namespace QuickModularPowerWithPreprocess {
    // all variables
    ll k;
    vector<ll> p;
    vector<ll> q;

    // O(1) modulo mul to calculate a^b mod m
    inline static
    ll modmul(ll a, ll b, ll m) {
        a = (a % m + m) % m;
        b = (b % m + m) % m;
        return ((a * b -
                 static_cast<ll>(static_cast<long double>(a) / m * b) * m) %
                m + m) % m;
    }

    // Preprocess
    inline static
    void init(ll a, ll m) {
        k = ceil(sqrt(static_cast<double>(m)));
        vector<ll>().swap(p);
        vector<ll>().swap(q);

        p.resize(k + 1);
        p.at(0) = 1 % m;
        for (int i = 1; i <= k; ++i) {
            p.at(i) = modmul(a, p.at(i - 1), m);
        }
        q.resize(k + 1);
        q.at(0) = 1 % m;
        for (int i = 1; i <= k; ++i) {
            // q[i] = a^k * q_{i-1} mod m = p.at(k) * q_{i-1} mod m
            q.at(i) = modmul(p.at(k), q.at(i - 1), m);
        }
    }

    // Query in O(1)
    inline static
    ll query(ll n) {
        ll n_prime = n % (MOD - 1);
        ll x = n_prime / k;
        ll y = n_prime % k;
        return modmul(q.at(x), p.at(y), MOD);
    }
}

namespace Tester {
    inline static
    ll modpow(ll a, ll n, ll M = MOD) {
        if (M == 1) return 0;
        ll r;
        for (r = 1, a %= M; n; a = (a * a) % M, n >>= 1)
            if (n % 2)
                r = (r * a) % M;
        return r;
    }

    auto get_random_n = []() {
        static ll lower_bound = 1;
        static ll upper_bound = 1000000000000000000;
        static random_device dev;
        static mt19937 random_generator(dev());
        static uniform_int_distribution dist(lower_bound, upper_bound);
        return dist(random_generator);
    };
}

int main() {

    int t = 10000000;
    ll a = 1147483648;
    ll b;
    // init
    QuickModularPowerWithPreprocess::init(a, MOD);
    while (t--) {
        b = Tester::get_random_n();
        assert(QuickModularPowerWithPreprocess::query(b) ==
               Tester::modpow(a, b, MOD));
    }
    return 0;
}