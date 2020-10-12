// https://loj.ac/problem/6279
//
// range sum, maintain a multiset for each block
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
int n;
int blocks;
vector<int> L;
vector<int> R;
vector<int> block;
vector<ll> add;
vector<multiset<ll> > mset;
inline void decompose() {
    blocks = sqrt(n);
    L.resize(blocks + 1);
    R.resize(blocks + 1);
    add.resize(blocks + 1);
    for (int i = 1; i <= blocks; ++i) {
        L.at(i) = (i - 1) * blocks + 1;
        R.at(i) = i * blocks;
    }
    if (R.back() < n) {
        L.emplace_back(R.back() + 1);
        R.emplace_back(n);
        add.emplace_back(0);
        ++blocks;
    }
    mset.resize(blocks + 1);
    for (int i = 1; i <= blocks; ++i) {
        for (int j = L.at(i); j <= R.at(i); ++j) {
            block.at(j) = i;
            mset.at(i).insert(A.at(j));
        }
    }
}
inline void range_add(int l, int r, ll k) {
    int l_block = block.at(l);
    int r_block = block.at(r);
    if (l_block == r_block) {
        for (int i = l; i <= r; ++i) {
            mset.at(l_block).erase(mset.at(l_block).lower_bound(A.at(i)));
            A.at(i) += k;
            mset.at(l_block).insert(A.at(i));
        }
    } else {
        for (int i = l_block + 1; i <= r_block - 1; ++i) {
            add.at(i) += k;
        }
        for (int i = l; i <= R.at(l_block); ++i) {
            mset.at(l_block).erase(mset.at(l_block).lower_bound(A.at(i)));
            A.at(i) += k;
            mset.at(l_block).insert(A.at(i));
        }
        for (int i = L.at(r_block); i <= r; ++i) {
            mset.at(r_block).erase(mset.at(r_block).lower_bound(A.at(i)));
            A.at(i) += k;
            mset.at(r_block).insert(A.at(i));
        }
    }
}
inline ll my_binary_search(const multiset<ll> &m, ll target, ll increment) {
    target -= increment;
    if (m.empty())
        return numeric_limits<ll>::min();
    if (*m.begin() >= target)
        return numeric_limits<ll>::min();
    return *(--m.lower_bound(target)) + increment;
}
inline ll linear_search_in_a_block(int l, int r, ll target) {
    ll result = numeric_limits<ll>::min();
    ll temp;
    ll increment = add.at(block.at(l));
    for (int i = l; i <= r; ++i) {
        temp = A.at(i) + increment;
        if (temp < target) {
            result = max(result, temp);
        }
    }
    return result;
}
inline ll pre(int l, int r, ll k) {
    int l_block = block.at(l);
    int r_block = block.at(r);
    ll result;
    if (l_block == r_block) {
        result = linear_search_in_a_block(l, r, k);
    } else {
        result = numeric_limits<ll>::min();
        for (int i = l_block + 1; i <= r_block - 1; ++i) {
            result = max(result, my_binary_search(mset.at(i), k, add.at(i)));
        }
        result = max(result, linear_search_in_a_block(l, R.at(l_block), k));
        result = max(result, linear_search_in_a_block(L.at(r_block), r, k));
    }
    return (result == numeric_limits<ll>::min()) ? (-1) : result;
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
            IO::writeln(SQRD::pre(l, r, c));
        }
    }
    return 0;
}
