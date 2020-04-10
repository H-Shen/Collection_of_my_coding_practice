// https://open.kattis.com/problems/nonprimefactors

#include <bits/extc++.h>

using namespace std;

const int N = 2000000 + 5;
int NPF[N];
int prime[N];
int isNotPrime[N] = {1, 1};
int num_prime = 0;

inline
void getPrimes() {
    for (int i = 2; i < N; i++) {
        if (!isNotPrime[i]) {
            prime[num_prime++] = i;
        }
        for (int j = 0; j < num_prime && i * prime[j] < N; j++) {
            isNotPrime[i * prime[j]] = 1;
            if (!(i % prime[j])) {
                break;
            }
        }
    }
}

inline
void getNPFs() {
    for (int i = 1; i < N; i++) {
        for (int j = 1; i * j < N; j++) {
            if (isNotPrime[i]) {
                NPF[i * j] += 1;
            }
        }
    }
}

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

int main() {

    getPrimes();
    getNPFs();

    int Q, a;
    IO::read(Q);
    while (Q--) {
        IO::read(a);
        IO::writeln(NPF[a]);
    }

    return 0;
}
