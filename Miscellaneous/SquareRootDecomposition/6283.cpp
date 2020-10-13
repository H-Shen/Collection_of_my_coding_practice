// https://loj.ac/problem/6283
//
// range add, range mul, modulo
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll MOD = 10007;

namespace IO {
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

// Do the modulo in the every step of the calculation to avoid overflow!
namespace SQRD {
vector<ll> A;
vector<int> block;
int n, blocks;
vector<ll> mul;
vector<ll> add;
vector<int> L;
vector<int> R;
inline void decompose() {
    blocks = sqrt(n);
    L.resize(blocks + 1);
    R.resize(blocks + 1);
    add.resize(blocks + 1);
    mul.resize(blocks + 1, 1);
    for (int i = 1; i <= blocks; ++i) {
        L.at(i) = (i - 1) * blocks + 1;
        R.at(i) = i * blocks;
    }
    if (R.back() < n) {
        L.emplace_back(R.back() + 1);
        R.emplace_back(n);
        add.emplace_back(0);
        mul.emplace_back(1);
        ++blocks;
    }
    for (int i = 1; i <= blocks; ++i) {
        for (int j = L.at(i); j <= R.at(i); ++j) {
            block.at(j) = i;
        }
    }
}
inline void reset_block(int block_id) {
    for (int i = L.at(block_id); i <= R.at(block_id); ++i) {
        A.at(i) = (A.at(i) * mul.at(block_id) + add.at(block_id)) % MOD;  // restore its original value
    }
    // reset the coeff
    mul.at(block_id) = 1;
    // reset the increment
    add.at(block_id) = 0;
}
inline ll get_value(int index) {
    int block_id = block.at(index);
    return (A.at(index) * mul.at(block_id) + add.at(block_id)) % MOD;
}
// (m1, a1) ---> (m1*m2, a1*m2)
inline void range_mul(int l, int r, ll c) {
    int l_block = block.at(l);
    int r_block = block.at(r);
    if (l_block == r_block) {
        reset_block(l_block);
        for (int i = l; i <= r; ++i) {
            A.at(i) = A.at(i) * c % MOD;
        }
    } else {
        for (int i = l_block + 1; i <= r_block - 1; ++i) {
            mul.at(i) = mul.at(i) * c % MOD;
            add.at(i) = add.at(i) * c % MOD;
        }
        reset_block(l_block);
        for (int i = l; i <= R.at(l_block); ++i) {
            A.at(i) = A.at(i) * c % MOD;
        }
        reset_block(r_block);
        for (int i = L.at(r_block); i <= r; ++i) {
            A.at(i) = A.at(i) * c % MOD;
        }
    }
}
// (m1, a1) ---> (m1, a1 + a2)
inline void range_add(int l, int r, ll c) {
    int l_block = block.at(l);
    int r_block = block.at(r);
    if (l_block == r_block) {
        reset_block(l_block);
        for (int i = l; i <= r; ++i) {
            A.at(i) = (A.at(i) + c) % MOD;
        }
    } else {
        for (int i = l_block + 1; i <= r_block - 1; ++i) {
            add.at(i) = (add.at(i) + c) % MOD;
        }
        reset_block(l_block);
        for (int i = l; i <= R.at(l_block); ++i) {
            A.at(i) = (A.at(i) + c) % MOD;
        }
        reset_block(r_block);
        for (int i = L.at(r_block); i <= r; ++i) {
            A.at(i) = (A.at(i) + c) % MOD;
        }
    }
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
        } else if (opt == 1) {
            SQRD::range_mul(l, r, c);
        } else {
            IO::writeln(SQRD::get_value(r));
        }
    }
    return 0;
}
