// https://ac.nowcoder.com/acm/contest/981/A

#include <bits/stdc++.h>

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


int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    size_t n, m, p;
    std::cin >> n >> m;

    std::vector<std::vector<long long> > A(n, std::vector<long long>(m));
    for (auto &&i : A) {
        for (auto &&j : i) {
            std::cin >> j;
        }
    }

    std::cin >> p;
    std::vector<std::vector<long long> > B(m, std::vector<long long>(p));
    for (auto &&i : B) {
        for (auto &&j : i) {
            std::cin >> j;
        }
    }

    printf("%s\n", matrixToString<long long>(matrixMul<long long>(A, B)).c_str());

    return 0;
}