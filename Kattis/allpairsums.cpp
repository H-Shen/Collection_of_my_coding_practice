// https://open.kattis.com/problems/allpairsums
//
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <complex>

using namespace std;
using ll = long long;

namespace IO {
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
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
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar('\n');
    }
    template<typename T, typename... Args>
    inline void writeln(T t, Args... args) {
        writeln(t); writeln(args...);
    }
}

namespace FFT {

    inline
    void
    bitReverse(std::vector<std::complex<double>> &arr) {
        int n = (int) arr.size();
        std::vector<int> rev(n);
        int half = n >> 1;
        for (int i = 0; i < n; ++i) {
            rev[i] = rev[i >> 1] >> 1;
            if (i & 1) {
                rev[i] += half;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i < rev[i]) {
                std::swap(arr[i], arr[rev[i]]);
            }
        }
    }

    inline
    void
    iterativeFFT(std::vector<std::complex<double>> &y, int inverseFFT) {
        bitReverse(y);
        int n = (int) y.size();
        for (int m = 2; m <= n; m <<= 1) {
            std::complex<double> w_m = exp(
                    std::complex<double>(0,inverseFFT * 2.0 * M_PI / m));
            for (int k = 0; k < n; k += m) {
                std::complex<double> w(1.0, 0.0);
                // Butterfly operation
                for (int j = k; j < k + (m >> 1); ++j) {
                    std::complex<double> u = y[j];
                    std::complex<double> t = w * y[j + (m >> 1)];
                    y[j] = u + t;
                    y[j + (m >> 1)] = u - t;
                    w *= w_m;
                }
            }
        }
        // Scale by n if it is inverseFFT
        if (inverseFFT == -1) {
            for (auto &i: y) {
                i /= n;
            }
        }
    }

    vector<ll> multiply(const vector<ll>& a, const vector<ll>& b) {
        vector<complex<double>> fa(a.begin(), a.end()), fb(b.begin(), b.end());
        int n = 1;
        while(n < (int)a.size() + (int)b.size() - 1)
            n <<= 1;
        fa.resize(n);
        fb.resize(n);

        iterativeFFT(fa, 1);
        iterativeFFT(fb, 1);
        for (int i = 0; i < n; i++)
            fa[i] *= fb[i];
        iterativeFFT(fa, -1);
        vector<ll> res(n);
        for (int i = 0; i < n; i++)
            res[i] = llround(fa[i].real());
        return res;
    }
}

constexpr int OFFSET = 100000;
constexpr int SIZE = 2*OFFSET+1;

int main(){
    int n, m, q, x;
    vector<ll> freqA(SIZE);
    vector<ll> freqB(SIZE);
    IO::read(n, m);
    for (int i = 0; i < n; ++i) {
        IO::read(x);
        ++freqA[x + OFFSET];
    }
    for (int i = 0; i < m; ++i) {
        IO::read(x);
        ++freqB[x + OFFSET];
    }
    vector<ll> conv = FFT::multiply(freqA, freqB);
    IO::read(q);
    while (q--) {
        IO::read(x);
        x += 2 * OFFSET;
        if (x < 0 || x >= (int)conv.size()) {
            IO::writeln(0);
        }
        else {
            IO::writeln(conv[x]);
        }
    }
    return 0;
}
