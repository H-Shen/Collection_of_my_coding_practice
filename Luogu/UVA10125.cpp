#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll MINIMAL_VAL = -536870920;

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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {

    int n;
    while (true) {
        IO::read(n);
        if (n == 0) break;
        vector<ll> A(n);
        unordered_map<ll, pair<ll, ll>, custom_hash> hash_table;
        for (int i = 0; i < n; ++i) {
            IO::read(A[i]);
        }
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                hash_table[A[i] + A[j]] = make_pair(A[i], A[j]);
            }
        }
        ll max_d = MINIMAL_VAL;
        int i;
        int j;
        decltype(hash_table)::const_iterator iter;
        for (i = 0; i < n - 1; ++i) {
            for (j = i + 1; j < n; ++j) {
                iter = hash_table.find(A[i] - A[j]);
                if (iter != hash_table.end() && A[i] != iter->second.first &&
                    A[i] != iter->second.second && A[j] != iter->second.first &&
                    A[j] != iter->second.second && max_d < A[i]) {
                    max_d = A[i];
                }
                iter = hash_table.find(A[j] - A[i]);
                if (iter != hash_table.end() && A[j] != iter->second.first &&
                    A[j] != iter->second.second && A[i] != iter->second.first &&
                    A[i] != iter->second.second && max_d < A[j]) {
                    max_d = A[j];
                }
            }
        }
        if (max_d == MINIMAL_VAL) {
            puts("no solution");
        } else {
            IO::writeln(max_d);
        }
    }
    return 0;
}
