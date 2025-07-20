#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <numeric>
#include <stdexcept>
#include <vector>
#include <iostream>

#define MATH_TEST

#ifdef MATH_TEST
#include <cassert>
#endif

using ll = long long;
using ull = unsigned long long;
using std::swap;
using std::vector;
using std::abs;
using std::accumulate;
using std::out_of_range;
using std::cout;
using std::endl;

/**
 * @brief Extended Euclidean algorithm.
 * Finds x, y such that a*x + b*y = gcd(|a|,|b|).
 * @return g = gcd(|a|,|b|)
 */
inline ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = (a >= 0 ? 1 : -1);
        y = 0;
        return abs(a);
    }
    ll x1, y1;
    ll g = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

/**
 * @brief Recursive GCD that handles negatives.
 * @return gcd(|a|,|b|)
 */
inline ll gcd_recursive(ll a, ll b) {
    a = abs(a);
    b = abs(b);
    if (b == 0) return a;
    return gcd_recursive(b, a % b);
}

/**
 * @brief Iterative GCD (Euclid’s algorithm).
 * @return gcd(|a|,|b|)
 */
inline ll gcd_iterative(ll a, ll b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}

#ifdef __GNUC__
/**
 * @brief Binary‐GCD (Stein’s) algorithm.
 */
inline ull binary_gcd(ull u, ull v) {
    if (u == 0 || v == 0) return u | v;
    unsigned shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    do {
        v >>= __builtin_ctz(v);
        if (u > v) swap(u, v);
        v -= u;
    } while (v);
    return u << shift;
}
#endif

/**
 * @brief GCD of all elements in a non‐empty array.
 * @throws out_of_range if A.empty()
 */
inline ll gcd_of_array(const vector<ll>& A) {
    if (A.empty()) {
        throw out_of_range("gcd_of_array: input vector is empty");
    }
    ll result = abs(A[0]);
    for (size_t i = 1; i < A.size(); ++i) {
        result = gcd_iterative(result, A[i]);
    }
    return result;
}

/**
 * @brief Least common multiple of two integers.
 * @return 0 if either is zero, else |a/gcd(a,b)*b|
 */
inline ll lcm(ll a, ll b) {
    a = abs(a);
    b = abs(b);
    if (a == 0 || b == 0) return 0;
    return a / gcd_iterative(a, b) * b;
}

/**
 * @brief LCM of all elements in a non‐empty array.
 * @throws out_of_range if A.empty()
 */
inline ll lcm_of_array(const vector<ll>& A) {
    if (A.empty()) {
        throw out_of_range("lcm_of_array: input vector is empty");
    }
    ll result = abs(A[0]);
    for (size_t i = 1; i < A.size(); ++i) {
        result = lcm(result, A[i]);
    }
    return result;
}

#ifdef MATH_TEST
int main() {
    // Test extended_gcd
    {
        ll x, y;
        ll g = extended_gcd(12381, -18199, x, y);
        assert(g == gcd_iterative(12381, 18199));
        assert(12381*x + -18199*y == g);
    }

#ifdef __GNUC__
    // Test binary_gcd
    assert(binary_gcd(4689933ULL, 2503455ULL) == 201ULL);
#endif

    // Test gcd_of_array and lcm_of_array
    vector<ll> v{2, 4, 6, 8};
    assert(gcd_of_array(v) == 2);
    assert(lcm_of_array(v) == 24);

    bool threw = false;
    try { gcd_of_array({}); } catch (...) { threw = true; }
    assert(threw);

    threw = false;
    try { lcm_of_array({}); } catch (...) { threw = true; }
    assert(threw);

    cout << "All tests passed." << endl;
    return 0;
}
#endif // MATH_TEST
