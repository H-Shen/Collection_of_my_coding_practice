// https://ac.nowcoder.com/acm/contest/981/C

#include <bits/stdc++.h>

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

    long long term0 = 1;
    long long term1 = 1;
    long long a = 1;
    long long b = 1;
    long long n, mod;
    std::cin >> n >> mod;

    if (n == 1) {
        std::cout << 1 % mod << std::endl;
    } else if (n == 2) {
        std::cout << 2 % mod << std::endl;
    } else {
        n += 2;
        auto tempVec0 = quickMatrixPower<long long>({{a, b}, {1, 0}}, n - 2, mod);
        auto tempVec1 = matrixMul(tempVec0, {{term1, 1}, {term0, 1}}, mod);

        // get f(n+2) mod m
        auto fib = tempVec1.front().front();
        // s(n) mod m = (f(n+2) mod m - 1 mod m) mod m
        std::cout << (fib - 1 % mod) % mod << std::endl;
    }

    return 0;
}