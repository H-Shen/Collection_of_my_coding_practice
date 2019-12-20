// https://ac.nowcoder.com/acm/contest/981/D

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

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long term0 = 1;
    long long term1 = 1;
    long long a = 1;
    long long b = 1;
    long long n, m;
    std::cin >> n >> m;

    switch (n) {
        case 1:
            std::cout << 1 % m << std::endl;
            break;
        case 2:
            std::cout << 3 % m << std::endl;
            break;
        case 3:
            std::cout << 9 % m << std::endl;
            break;
        case 4:
            std::cout << 21 % m << std::endl;
            break;
        default:
            // f(n + 2) % m
            auto fib_n_add_2 = matrixMul(quickMatrixPower<long long>({{a, b}, {1, 0}}, n, m), {{term1, 1}, {term0, 1}}, m).front().front();
            // f(n + 3) % m
            auto fib_n_add_3 = matrixMul(quickMatrixPower<long long>({{a, b}, {1, 0}}, n + 1, m), {{term1, 1}, {term0, 1}}, m).front().front();
            // T(n) % m = ((n % m) * (f(n + 2) % m)) % m - f(n + 3) % m + 2 % m
            // We MUST add extra m to make sure (n * fib_n_add_2 + m - fib_n_add_3 + 2) > 0
            auto T_n = (n * fib_n_add_2 + m - fib_n_add_3 + 2) % m;
            std::cout << T_n << std::endl;
            break;
    }

    return 0;
}