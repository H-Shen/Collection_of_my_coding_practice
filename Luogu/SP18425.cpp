#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
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
}

namespace FFT {

    using base = complex<double>;

    void fft(vector<base> &a, bool invert) {
        ll n = (ll) a.size();
        for (ll i = 1, j = 0; i < n; ++i) {
            int bit = n >> 1;
            for (; j >= bit; bit >>= 1)
                j -= bit;
            j += bit;
            if (i < j)
                swap(a[i], a[j]);
        }
        for (ll len = 2; len <= n; len <<= 1) {
            double ang = 2 * M_PI / len * (invert ? -1 : 1);
            base wlen(cos(ang), sin(ang));
            for (ll i = 0; i < n; i += len) {
                base w(1);
                for (int j = 0; j < len / 2; ++j) {
                    base u = a[i + j], v = a[i + j + len / 2] * w;
                    a[i + j] = u + v;
                    a[i + j + len / 2] = u - v;
                    w *= wlen;
                }
            }
        }
        if (invert)
            for (ll i = 0; i < n; ++i)
                a[i] /= n;
    }

    void multiply(const vector<ll> &a,
                  const vector<ll> &b,
                  vector<ll> &res) {
        vector<base> fa(a.begin(), a.end()),
                fb(b.begin(), b.end());
        size_t n = 1;
        while (n < max(a.size(), b.size())) n <<= 1;
        n <<= 1;
        fa.resize(n);
        fb.resize(n);
        fft(fa, false), fft(fb, false);
        for (size_t i = 0; i < n; ++i)
            fa[i] *= fb[i];
        fft(fa, true);
        res.resize(n);
        for (size_t i = 0; i < n; ++i)
            res[i] = ll(fa[i].real() + 0.5);
    }
}

int main() {

    ll t, n, m;
    IO::read(t);
    while (t--) {
        IO::read(n);
        vector<ll> A(n + 1);
        for (auto &i : A) {
            IO::read(i);
        }
        m = n;
        vector<ll> B(m + 1);
        for (auto &i : B) {
            IO::read(i);
        }
        vector<ll> C;
        FFT::multiply(A, B, C);
        bool first_item = true;
        ll total = 2 * n + 1;
        for (ll i = 0; i < total; ++i) {
            if (first_item) {
                first_item = false;
            } else {
                putchar(' ');
            }
            IO::write(C.at(i));
        }
        putchar('\n');
    }


    return 0;
}
