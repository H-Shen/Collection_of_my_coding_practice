// https://loj.ac/problem/6278
//
// Range update, query the occurrence of numbers < x in all blocks
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
int n, blocks;
vector<ll> A;
vector<ll> A_after_sort;
vector<ll> add;  // add.at(i) = the increment of each element in the block 'i'

vector<int> L;      // L.at(i) = the left bound of the block 'i' (inclusive)
vector<int> R;      // R.at(i) = the right bound of the block 'i' (inclusive)
vector<int> block;  // block.at(i) = the block that the i-th element of A belongs to

void resort(int block_id) {
    for (int i = L.at(block_id); i <= R.at(block_id); ++i) {
        A_after_sort.at(i) = A.at(i);
    }
    sort(A_after_sort.begin() + L.at(block_id), A_after_sort.begin() + R.at(block_id) + 1);
}

// Update A[i] to A[i]+k such that l <= i <= r and re-adjust A_after_sort
void range_add(int l, int r, ll k) {
    int l_block = block.at(l);
    int r_block = block.at(r);
    // Case 1: l and r are in the same block
    if (l_block == r_block) {
        for (int i = l; i <= r; ++i) {
            A.at(i) += k;
        }
        // re-sort the whole block
        resort(l_block);
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
        // Re-sort l_block
        resort(l_block);
        // Process elements in r_block one by one, from the start of the block that 'r' belongs to to 'r'
        for (int i = L.at(r_block); i <= r; ++i) {
            A.at(i) += k;
        }
        // Re-sort r_block
        resort(r_block);
    }
}

// Get number of elements in the range [l,r] such that each element < k
int get_elements(int l, int r, ll k) {
    int l_block = block.at(l);
    int r_block = block.at(r);
    int count = 0;
    // Case 1:
    for (int i = l_block + 1; i <= r_block - 1; ++i) {
        ll target = k - add.at(i);
        if (target < A_after_sort.at(L.at(i))) {
            continue;
        } else if (target > A_after_sort.at(R.at(i))) {
            count += (R.at(i) - L.at(i) + 1);
        } else {
            auto iter0 = A_after_sort.begin() + L.at(i);
            auto iter1 = A_after_sort.begin() + R.at(i) + 1;
            count += (int)((--lower_bound(iter0, iter1, target)) - iter0 + 1);
        }
    }
    // Case 2:  Dont forget this case!!
    if (l_block == r_block) {
        for (int i = l; i <= r; ++i) {
            if (A.at(i) + add.at(l_block) < k) {
                ++count;
            }
        }
    }
    // Case 3:
    else {
        for (int i = l; i <= R.at(l_block); ++i) {
            if (A.at(i) + add.at(l_block) < k) {
                ++count;
            }
        }
        for (int i = L.at(r_block); i <= r; ++i) {
            if (A.at(i) + add.at(r_block) < k) {
                ++count;
            }
        }
    }
    return count;
}

int main() {
    IO::read(n);
    A.resize(n + 1);
    A_after_sort.resize(n + 1);
    block.resize(n + 1);
    // read the original array
    for (int i = 1; i <= n; ++i) {
        IO::read(A.at(i));
        A_after_sort.at(i) = A.at(i);
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
    // Sort each block in A_after_sort
    for (int i = 1; i <= blocks; ++i) {
        sort(A_after_sort.begin() + L.at(i), A_after_sort.begin() + R.at(i) + 1);
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
    for (int i = 1; i <= n; ++i) {
        IO::read(opt);
        if (opt == 0) {
            IO::read(l, r, c);
            range_add(l, r, c);
        } else {
            IO::read(l, r, c);
            IO::writeln(get_elements(l, r, c * c));
        }
    }
    return 0;
}
