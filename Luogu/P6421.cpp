#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

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

namespace EulerPrimeSieve {

    constexpr int MAXN = 100005;
    constexpr int MAXIMAL_PRIMES = 9593;
    int prime[MAXIMAL_PRIMES] = {0};
    int num_prime = 0;
    bool isNotPrime[MAXN] = {true, true};

    // Generate the prime table from 1 to MAXN
    inline static
    void init() {
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
}

vector<ll> primes;
vector<bool> A;

int main() {

    EulerPrimeSieve::init();
    for (int i = 0; i < EulerPrimeSieve::MAXIMAL_PRIMES - 1; ++i) {
        primes.emplace_back(EulerPrimeSieve::prime[i]);
    }

    ll N, K;
    IO::read(N, K);
    A.resize(N - 2 + 1);
    for (ll i = 2; i <= N; ++i) {
        A.at(i - 2) = true;
    }
    auto prime_iter = primes.cbegin();
    ll multiplier = 1;
    ll temp;
    while (true) {
        temp = multiplier * (*prime_iter);
        if (temp > N) {
            multiplier = 1;
            ++prime_iter;
            continue;
        }
        if (A.at(temp - 2)) {
            A.at(temp - 2) = false;
            --K;
        }
        ++multiplier;
        if (K == 0) {
            IO::writeln(temp);
            break;
        }
    }

    return 0;
}
