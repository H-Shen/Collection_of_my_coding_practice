#include <iostream>

// 1. A simple implementation of matrix whose size is fixed
// 2. Using long long or __int128 as type T is recommended
// 3. Use on coding competitions only
// 4. Arguments are not checked for validity, make sure the validity before using
// 5. All data members are exposed, no things like OOP, just some operators are overloaded
// 6. Remove MOD if you dont need it
template<typename T, int size>
struct Mat {
    T A[size][size]{};
    T mod;

    explicit Mat(const T &mod) : mod(mod) {}

    Mat operator+(const Mat &lhs) const {
        Mat res;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                res.A[i][j] = (A[i][j] + lhs.A[i][j]) % mod;
            }
        }
        return res;
    }

    Mat operator-(const Mat &lhs) const {
        Mat res;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                res.A[i][j] = (A[i][j] - lhs.A[i][j]) % mod;
            }
        }
        return res;
    }

    Mat operator*(const Mat &lhs) const {
        Mat res(mod);
        T temp;
        for (int i = 0; i < size; ++i) {
            for (int k = 0; k < size; ++k) {
                temp = A[i][k];
                for (int j = 0; j < size; ++j) {
                    res.A[i][j] = (res.A[i][j] + lhs.A[k][j] * temp) % mod;
                }
            }
        }
        return res;
    }

    Mat operator^(T n) const {
        Mat res(mod), base(mod);
        for (int i = 0; i < size; ++i) {
            res.A[i][i] = 1;
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                base.A[i][j] = A[i][j] % mod;
            }
        }
        while (n) {
            if (n & 1) {
                res = res * base;
            }
            base = base * base;
            n >>= 1;
        }
        return res;
    }
};

template<typename T, int size>
void debug_print(const Mat<T, size> &m) {
    std::cout << typeid(T).name() << ' ' << size << ' ' << m.mod << std::endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << m.A[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

int main() {

    Mat<long long, 5> m(123);
    debug_print(m);

    return 0;
}

