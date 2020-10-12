// https://loj.ac/problem/6277
//
// Range update, query value in an index
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

namespace IO {
template <typename T>
inline bool can_read(T &t) {
    int n = 0;
    int ch = getchar_unlocked();
    while (!isdigit(ch)) {
        if (ch == EOF)
            return false;
        n |= ch == '-';
        ch = getchar_unlocked();
    }
    t = 0;
    while (isdigit(ch)) {
        t = t * 10 + ch - 48;
        ch = getchar_unlocked();
    }
    if (n)
        t = -t;
    return true;
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

// SquareRootDecompose
int n, m, blocks;
vector<ll> A;
vector<int> L;      // L.at(i) = the left bound of the block 'i' (inclusive)
vector<int> R;      // R.at(i) = the right bound of the block 'i' (inclusive)
vector<int> block;  // block.at(i) = the block that the i-th element of A belongs to
vector<ll> add;     // add.at(i) = the increment of each element in the block 'i'

// Update A[i] to A[i]+k such that l <= i <= r
void range_add(int l, int r, ll k) {
    int l_block = block.at(l);
    int r_block = block.at(r);
    // Case 1: [l, r] is in the same block
    if (l_block == r_block) {
        for (int i = l; i <= r; ++i) {
            A.at(i) += k;
        }
    }
    // Case 2: [l, r] lies across at least 2 blocks
    else {
        // Update all blocks between l_block and r_block
        for (int i = l_block + 1; i <= r_block - 1; ++i) {
            add.at(i) += k;
        }
        // Process elements in l_block one by one, from 'l' to the end of the block that 'l' belongs to
        for (int i = l; i <= R.at(l_block); ++i) {
            A.at(i) += k;
        }
        // Process elements in r_block one by one, from the start of the block that 'r' belongs to to 'r'
        for (int i = L.at(r_block); i <= r; ++i) {
            A.at(i) += k;
        }
    }
}

ll get_value(int index) { return A.at(index) + add.at(block.at(index)); }

int main() {
    IO::read(n);
    A.resize(n + 1);
    block.resize(n + 1);
    // read the original array
    for (int i = 1; i <= n; ++i) {
        IO::read(A.at(i));
    }
    // start split the array into blocks
    blocks = sqrt(n);  // floor(sqrt(n))
    L.resize(blocks + 1);
    R.resize(blocks + 1);
    add.resize(blocks + 1);
    for (int i = 1; i <= blocks; ++i) {
        L.at(i) = (i - 1) * blocks + 1;
        R.at(i) = i * blocks;
    }
    // Pack the rest elements into another block
    if (R.at(blocks) < n) {
        L.emplace_back(R.back() + 1);
        R.emplace_back(n);
        add.emplace_back(0);
        ++blocks;
    }
    // Update 'block'
    for (int i = 1; i <= blocks; ++i) {
        for (int j = L.at(i); j <= R.at(i); ++j) {
            block.at(j) = i;
        }
    }
    // Start reading queries
    int opt, l, r;
    ll c;
    while (IO::can_read(opt)) {
        if (opt == 0) {
            IO::read(l, r, c);
            range_add(l, r, c);
        } else {
            IO::read(l, r, c);
            IO::writeln(get_value(r));
        }
    }
    return 0;
}
