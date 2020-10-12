// https://loj.ac/problem/6280
//
// range add, range sum
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

namespace IO {
inline void read_alpha(char &t) {
    int c = getchar_unlocked();
    t = 0;
    while (!isalpha(c)) c = getchar_unlocked();
    while (isalpha(c)) t = c, c = getchar_unlocked();
}
template <typename T>
inline void read(T &t) {
    int n = 0;
    int c = getchar_unlocked();
    t = 0;
    while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
    while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
    if (n)
        t = -t;
}
template <typename T, typename... Args>
inline void read(T &t, Args &... args) {
    read(t);
    read(args...);
}

template <typename T>
inline void write(T x) {
    if (x < 0)
        x = -x, putchar_unlocked('-');
    if (x > 9)
        write(x / 10);
    putchar_unlocked(x % 10 + 48);
}

template <typename T>
inline void writeln(T x) {
    write(x);
    putchar_unlocked('\n');
}
}  // namespace IO

namespace SQRD {
vector<ll> A;
vector<int> block;
int n, blocks;
vector<ll> add;
vector<ll> sum;
vector<int> L;
vector<int> R;
inline void decompose() {
    blocks = sqrt(n);
    L.resize(blocks + 1);
    R.resize(blocks + 1);
    sum.resize(blocks + 1);
    add.resize(blocks + 1);
    for (int i = 1; i <= blocks; ++i) {
        L.at(i) = (i - 1) * blocks + 1;
        R.at(i) = i * blocks;
    }
    if (R.back() < n) {
        L.emplace_back(R.back() + 1);
        R.emplace_back(n);
        ++blocks;
        sum.emplace_back(0);
        add.emplace_back(0);
    }
    for (int i = 1; i <= blocks; ++i) {
        for (int j = L.at(i); j <= R.at(i); ++j) {
            block.at(j) = i;
            sum.at(i) += A.at(j);
        }
    }
}
inline void range_add(int l, int r, ll k) {
    int l_block = block.at(l);
    int r_block = block.at(r);
    if (l_block == r_block) {
        for (int i = l; i <= r; ++i) {
            A.at(i) += k;
            sum.at(l_block) += k;
        }
    } else {
        for (int i = l_block + 1; i <= r_block - 1; ++i) {
            add.at(i) += k;
        }
        for (int i = l; i <= R.at(l_block); ++i) {
            A.at(i) += k;
            sum.at(l_block) += k;
        }
        for (int i = L.at(r_block); i <= r; ++i) {
            A.at(i) += k;
            sum.at(r_block) += k;
        }
    }
}
inline ll range_sum(int l, int r, ll mod) {
    int l_block = block.at(l);
    int r_block = block.at(r);
    ll result = 0;
    if (l_block == r_block) {
        for (int i = l; i <= r; ++i) {
            result += A.at(i) + add.at(l_block);
        }
        result %= mod;
    } else {
        for (int i = l_block + 1; i <= r_block - 1; ++i) {
            result += sum.at(i) + add.at(i) * (R.at(i) - L.at(i) + 1);
        }
        for (int i = l; i <= R.at(l_block); ++i) {
            result += A.at(i) + add.at(l_block);
        }
        for (int i = L.at(r_block); i <= r; ++i) {
            result += A.at(i) + add.at(r_block);
        }
        result %= mod;
    }
    return result;
}
}  // namespace SQRD

int main() {
    IO::read(SQRD::n);
    SQRD::A.resize(SQRD::n + 1);
    SQRD::block.resize(SQRD::n + 1);
    for (int i = 1; i <= SQRD::n; ++i) {
        IO::read(SQRD::A.at(i));
    }
    SQRD::decompose();
    int opt, l, r;
    ll c;
    for (int i = 1; i <= SQRD::n; ++i) {
        IO::read(opt, l, r, c);
        if (opt == 0) {
            SQRD::range_add(l, r, c);
        } else {
            IO::writeln(SQRD::range_sum(l, r, c + 1));
        }
    }
    return 0;
}
