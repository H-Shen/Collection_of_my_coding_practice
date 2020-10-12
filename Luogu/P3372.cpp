// An example that uses square root decomposition
//
#include <bits/stdc++.h>

using namespace std;
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

// SquareRootDecompose
int n, m, blocks;
vector<ll> A;
vector<int> L;  // L.at(i) = the left bound of the block 'i' (inclusive)
vector<int> R;  // R.at(i) = the right bound of the block 'i' (inclusive)
vector<ll> sum; // sum.at(i) = the sum of the block 'i'
vector<int> block; // block.at(i) = the block that the i-th element of A belongs to
vector<ll> add; // add.at(i) = the increment of each element in the block 'i'

// Update A[i] to A[i]+k such that l <= i <= r
void range_add(int l, int r, ll k) {
    int l_block = block.at(l);
    int r_block = block.at(r);
    // Case 1: [l, r] is in the same block
    if (l_block == r_block) {
        for (int i = l; i <= r; ++i) {
            A.at(i) += k;
            sum.at(l_block) += k;
        }
    }
    // Case 2: [l, r] lies across at least 2 blocks
    else {
        // Policy:
        // If every element in the block is updated, we update 'add',
        // otherwise, we update 'sum'.

        // Update all blocks between l_block and r_block
        for (int i = l_block + 1; i <= r_block - 1; ++i) {
            add.at(i) += k;
        }
        // Process elements in l_block one by one, from 'l' to the end of the block that 'l' belongs to
        for (int i = l; i <= R.at(l_block); ++i) {
            A.at(i) += k;
            sum.at(l_block) += k;
        }
        // Process elements in r_block one by one, from the start of the block that 'r' belongs to to 'r'
        for (int i = L.at(r_block); i <= r; ++i) {
            A.at(i) += k;
            sum.at(r_block) += k;
        }
    }
}

// Query the sum from A[l] to A[r]
ll range_sum(int l, int r) {
    int l_block = block.at(l);
    int r_block = block.at(r);
    ll result = 0;
    // Case 1: [l, r] is in the same block
    if (l_block == r_block) {
        for (int i = l; i <= r; ++i) {
            result += A.at(i) + add.at(l_block);
        }
    }
    // Case 2: [l, r] lies across at least 2 blocks
    else {
        for (int i = l_block + 1; i <= r_block - 1; ++i) {
            int length_of_current_block = R.at(i) - L.at(i) + 1;
            result += sum.at(i) + add.at(i) * length_of_current_block;
        }
        for (int i = l; i <= R.at(l_block); ++i) {
            result += A.at(i) + add.at(l_block);
        }
        for (int i = L.at(r_block); i <= r; ++i) {
            result += A.at(i) + add.at(r_block);
        }
    }
    return result;
}

int main() {

    IO::read(n, m);
    A.resize(n + 1);
    block.resize(n + 1);
    // read the original array
    for (int i = 1; i <= n; ++i) {
        IO::read(A.at(i));
    }
    // start split the array into blocks
    blocks = sqrt(n);   // floor(sqrt(n))
    L.resize(blocks + 1);
    R.resize(blocks + 1);
    add.resize(blocks + 1);
    sum.resize(blocks + 1);
    for (int i = 1; i <= blocks; ++i) {
        L.at(i) = (i - 1) * blocks + 1;
        R.at(i) = i * blocks;
    }
    // Pack the rest elements into another block
    if (R.at(blocks) < n) {
        L.emplace_back(R.back() + 1);
        R.emplace_back(n);
        add.emplace_back(0);
        sum.emplace_back(0);
        ++blocks;
    }
    // Update 'sum' and 'block'
    for (int i = 1; i <= blocks; ++i) {
        for (int j = L.at(i); j <= R.at(i); ++j) {
            block.at(j) = i;
            sum.at(i) += A.at(j);
        }
    }
    // Start reading queries
    int op, x, y;
    ll k;
    while (m--) {
        IO::read(op);
        if (op == 1) {
            IO::read(x, y, k);
            range_add(x, y, k);
        } else {
            IO::read(x, y);
            IO::writeln(range_sum(x, y));
        }
    }
    return 0;
}
