#include <cassert>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

using ll = long long;
static constexpr ll MOD = 1'000'000'007;

// Computes base^n mod MOD in O(1) after O(√MOD) preprocessing
class QuickMod {
public:
    QuickMod(ll base, ll mod = MOD)
        : base_(base % mod), mod_(mod)
    {
        k_ = static_cast<ll>(std::ceil(std::sqrt(static_cast<double>(mod_))));
        p_.reserve(k_ + 1);
        q_.reserve(k_ + 1);

        // p_[i] = base^i mod
        p_.push_back(1);
        for (ll i = 1; i <= k_; ++i) {
            p_.push_back(modMul(base_, p_[i - 1]));
        }

        // q_[i] = base^(k*i) mod
        ll ak = p_[k_];
        q_.push_back(1);
        for (ll i = 1; i <= k_; ++i) {
            q_.push_back(modMul(ak, q_[i - 1]));
        }
    }

    // Query base^n mod in O(1)
    ll operator()(ll n) const noexcept {
        // reduce exponent modulo φ(mod) since mod is prime
        ll e = n % (mod_ - 1);
        ll x = e / k_;
        ll y = e % k_;
        return modMul(q_[x], p_[y]);
    }

private:
    // Safe multiplication modulo 'mod_' without relying on 128-bit
    ll modMul(ll a, ll b) const noexcept {
        a %= mod_;
        b %= mod_;
        ll result = 0;
        while (b > 0) {
            if (b & 1) {
                result = result + a;
                if (result >= mod_) result -= mod_;
            }
            a = a + a;
            if (a >= mod_) a -= mod_;
            b >>= 1;
        }
        return result;
    }

    ll base_, mod_, k_;
    std::vector<ll> p_, q_;
};

// Standard binary exponentiation for verification
static ll modPow(ll base, ll exp, ll mod = MOD) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

// Generate random n in [1, 1e18]
ll randomN() {
    static std::mt19937_64 gen{std::random_device{}()};
    static std::uniform_int_distribution<ll> dist(1, 1'000'000'000'000'000'000LL);
    return dist(gen);
}

int main() {
    constexpr int TEST_COUNT = 100000;
    const ll base = 1'147'483'648LL;

    QuickMod quick{base};

    for (int i = 0; i < TEST_COUNT; ++i) {
        ll n = randomN();
        assert(quick(n) == modPow(base, n));
    }

    std::cout << "All tests passed\n";
    return 0;
}
