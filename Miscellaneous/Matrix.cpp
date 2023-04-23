#include <cassert>
#include <iostream>
#include <string>
#include <vector>

template<typename T>
inline static
std::vector<std::vector<T> >
matrixAdd(const std::vector<std::vector<T> > &A, const std::vector<std::vector<T> > &B, bool isAddition) {
    // Case 1:
    if (A.empty()) {
        return B;
    }
    // Case 2:
    if (B.empty()) {
        return A;
    }
    // Case 3:
    if (A.size() != B.size() || A.front().size() != B.front().size()) {
        throw std::out_of_range("");
    }
    // Case 4:
    std::vector<std::vector<T> > C(A.size(), std::vector<T>(A.front().size()));
    for (size_t i = 0; i != C.size(); ++i) {
        for (size_t j = 0; j != C.at(i).size(); ++j) {
            if (isAddition) {
                C.at(i).at(j) = A.at(i).at(j) + B.at(i).at(j);
            } else {
                C.at(i).at(j) = A.at(i).at(j) - B.at(i).at(j);
            }
        }
    }
    return C;
}

template<typename T>
inline static
void matrixScalar(const T &c, std::vector<std::vector<T> > &A) {
    for (auto &&i : A) {
        for (auto &&j : i) {
            j *= c;
        }
    }
}

template<typename T>
inline static
std::vector<std::vector<T> > matrixRotation(const std::vector<std::vector<T> > &A) {
    // Case 1:
    if (A.empty() || A.front().empty()) {
        return std::vector<std::vector<T> >();
    }
    // Case 2:
    std::vector<std::vector<T> > result(A.front().size(), std::vector<T>(A.size()));
    for (size_t i = 0; i != result.size(); ++i) {
        for (size_t j = 0; j != result.at(i).size(); ++j) {
            result.at(i).at(j) = A.at(j).at(i);
        }
    }
    return result;
}

template<typename T>
inline static
std::vector<std::vector<T> > matrixMul(const std::vector<std::vector<T> > &A, const std::vector<std::vector<T> > &B) {

    // Case 1:
    if (A.empty() || B.empty() || A.at(0).empty() || B.at(0).empty() || A.at(0).size() != B.size()) {
        throw std::out_of_range("");
    }

    // Case 2:
    std::vector<std::vector<T> > C(A.size(), std::vector<T>(B.at(0).size()));
    for (size_t i = 0; i != A.size(); ++i) {
        for (size_t j = 0; j != B.at(0).size(); ++j) {
            for (size_t k = 0; k != A.at(0).size(); ++k) {
                C.at(i).at(j) += A.at(i).at(k) * B.at(k).at(j);
            }
        }
    }
    return C;
}

template<typename T>
inline static
std::string matrixToString(const std::vector<std::vector<T> > &C) {

    std::string result;
    if (!C.empty()) {
        size_t row = C.size();
        size_t col = C.at(0).size();
        bool firstItem;
        for (size_t i = 0; i != row; ++i) {
            firstItem = true;
            for (size_t j = 0; j != col; ++j) {
                if (firstItem) {
                    firstItem = false;
                } else {
                    result.push_back(' ');
                }
                result.append(std::to_string(C.at(i).at(j)));
            }
            if (i != row - 1) {
                result.push_back('\n');
            }
        }
    }
    return result;
}

// matrixMulMod % m: O(n^3)
template<typename T>
inline static
std::vector<std::vector<T> >
matrixMul(const std::vector<std::vector<T> > &A,
          const std::vector<std::vector<T> > &B, const T &mod) {

    // Case 1:
    if (A.empty() || B.empty() || A.at(0).empty() || B.at(0).empty() ||
        A.at(0).size() != B.size()) {
        throw std::out_of_range("");
    }

    // Case 2:
    std::vector<std::vector<T> > C(A.size(), std::vector<T>(B.at(0).size()));
    for (size_t i = 0; i != A.size(); ++i) {
        for (size_t j = 0; j != B.at(0).size(); ++j) {
            for (size_t k = 0; k != A.at(0).size(); ++k) {
                C.at(i).at(j) =
                        C.at(i).at(j) + A.at(i).at(k) * B.at(k).at(j) % mod;
            }
            C.at(i).at(j) %= mod;
        }
    }
    return C;
}

// Quick power of matrix with modulo: O(n^3 * log(power))
template<typename T>
inline static
std::vector<std::vector<T> >
quickMatrixPower(std::vector<std::vector<T> > A, T power, T m) {

    // Case 1:
    if (A.empty() || A.front().empty() || A.size() != A.front().size()) {
        throw std::out_of_range("");
    }

    // Case 2:
    // A = A % m
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
    // log(n)
    while (power > 0) {
        if (power & 1) {
            res = matrixMul(res, A, m);
        }
        A = matrixMul(A, A, m);
        power >>= 1;
    }
    return res;
}

int main() {

    return 0;
}

