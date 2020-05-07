#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr ll MOD = 1000000007;

namespace IO {
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar_unlocked();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }

    template<typename T, typename... Args>
    inline
    void read(T &t, Args &... args) {
        read(t);
        read(args...);
    }

    template<typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

// matrixMul % m
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


template<typename T>
inline static
std::vector<std::vector<T> >
quickMatrixPower(std::vector<std::vector<T> > A, T n, T m) {

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

//Since
//\begin{equation*}
//\begin{pmatrix}
//1 & 0 & 1 \\
//1 & 0 & 0 \\
//0 & 1 & 0
//\end{pmatrix}
//\begin{pmatrix}
//a_{x-1} \\
//a_{x-2} \\
//a_{x-3}
//\end{pmatrix} =
//\begin{pmatrix}
//a_{x} \\
//a_{x-1} \\
//a_{x-2}
//\end{pmatrix}
//\end{equation*}
//We have
//\begin{equation*}
//\begin{pmatrix}
//1 & 0 & 1 \\
//1 & 0 & 0 \\
//0 & 1 & 0
//\end{pmatrix}^k
//\begin{pmatrix}
//a_{3} \\
//a_{2} \\
//a_{1}
//\end{pmatrix} =
//\begin{pmatrix}
//1 & 0 & 1 \\
//1 & 0 & 0 \\
//0 & 1 & 0
//\end{pmatrix}^k
//\begin{pmatrix}
//1 \\
//1 \\
//1
//\end{pmatrix} =
//\begin{pmatrix}
//a_{k+3} \\
//a_{k+2} \\
//a_{k+1}
//\end{pmatrix}
//\end{equation*}
//And $a_{1}=a_{2}=a_{3}=1$

int main() {

    int T;
    ll n;
    IO::read(T);
    while (T--) {
        IO::read(n);
        if (n <= 3) {
            IO::writeln(1);
        } else {
            auto tempVec0 = quickMatrixPower<ll>({{1, 0, 1},
                                                  {1, 0, 0},
                                                  {0, 1, 0}}, n - 3, MOD);
            ll a_1 = 1;
            ll a_2 = 1;
            ll a_3 = 1;
            auto tempVec1 = matrixMul(tempVec0, {{a_3, 1, 1},
                                                 {a_2, 1, 1},
                                                 {a_1, 1, 1}}, MOD);
            IO::writeln(tempVec1.front().front());
        }
    }

    return 0;
}
