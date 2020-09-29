#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 20005;

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar_unlocked(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

template<int MAXN>
struct EulerPrimeSieve {
    array<int, MAXN> prime;
    int num_prime = 0;
    array<bool, MAXN> isNotPrime;
    // Generate the prime table from 1 to MAXN
    constexpr
    EulerPrimeSieve() : prime(), isNotPrime() {
        isNotPrime[0] = true;
        isNotPrime[1] = true;
        for (int i = 2; i < MAXN; i++) {
            if (!isNotPrime[i])
                prime[num_prime++] = i;
            for (int j = 0; j < num_prime && i * prime[j] < MAXN; j++) {
                isNotPrime[i * prime[j]] = true;
                if (!(i % prime[j]))
                    break;
            }
        }
    }
};

constexpr static auto primeList = EulerPrimeSieve<MAXN>();

inline
void f(int a, int b, int c) {
    IO::write(a);
    putchar_unlocked(' ');
    IO::write(b);
    putchar_unlocked(' ');
    IO::writeln(c);
}

int main() {

    int n, a, b, c;
    IO::read(n);
    for (int i = 0; i < primeList.num_prime; ++i) {
        for (int j = i; j < primeList.num_prime; ++j) {
            a = primeList.prime[i];
            b = primeList.prime[j];
            c = n - a - b;
            if (c >= 1 && c < MAXN && !primeList.isNotPrime[c]) {
                f(a, b, c);
                return 0;
            }
        }
    }
    return 0;
}