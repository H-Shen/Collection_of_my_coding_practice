#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr ll MOD = 100000000;

// matrixMul % m
template<typename T>
inline static
std::vector<std::vector<T> >
matrixMul(const std::vector<std::vector<T> > &A, const std::vector<std::vector<T> > &B, const T &mod) {

    // Case 1:
    if (A.empty() || B.empty() || A.at(0).empty() || B.at(0).empty() || A.at(0).size() != B.size()) {
        throw std::out_of_range("");
    }

    // Case 2:
    std::vector<std::vector<T> > C(A.size(), std::vector<T>(B.at(0).size()));
    for (size_t i = 0; i != A.size(); ++i) {
        for (size_t j = 0; j != B.at(0).size(); ++j) {
            for (size_t k = 0; k != A.at(0).size(); ++k) {
                C.at(i).at(j) = C.at(i).at(j) + A.at(i).at(k) * B.at(k).at(j) % mod;
            }
            C.at(i).at(j) %= mod;
        }
    }
    return C;
}


template<typename T>
inline static
std::vector<std::vector<T> > quickMatrixPower(std::vector<std::vector<T> > A, T n, T m) {

    // Case 1:
    if (A.empty() || A.front().empty() || A.size() != A.front().size()) {
        throw std::out_of_range("");
    }

    // Case 2:
    // A = A % m;
    for (size_t i = 0; i != A.size(); ++i) {
        for (size_t j = 0; j != A.at(0).size(); ++j) {
            A.at(i).at(j) %= m;
        }
    }
    // Initialize res as an identity matrix;
    std::vector<std::vector<T> > res(A.size(), std::vector<T>(A.size()));
    T initialValue{1};
    for (size_t i = 0; i != res.size(); ++i) {
        res.at(i).at(i) = initialValue;
    }
    while (n > 0) {
        // If n is odd.
        if (n & 1) {
            res = matrixMul(res, A, m);
        }
        // If n is even.
        A = matrixMul(A, A, m);
        n >>= 1;
    }
    return res;
}

int main() {

    ll n, m;
    scanf("%lld %lld", &n, &m);

    ll term0 = 1;
    ll term1 = 1;
    ll a = 1;
    ll b = 1;
    ll item = __gcd(m, n);  // gcd(F(n), F(m)) = F(gcd(n, m))

    if (item == 0) {
        printf("0\n");
    } else if (item <= 2) {
        printf("%lld\n", term1 % MOD);
    } else {
        auto tempVec0 = quickMatrixPower<ll>({{a, b},
                                                     {1, 0}}, item - 2, MOD);
        auto tempVec1 = matrixMul(tempVec0, {{term1, 1},
                                             {term0, 1}}, MOD);
        printf("%lld\n", tempVec1.front().front());
    }
    return 0;
}
