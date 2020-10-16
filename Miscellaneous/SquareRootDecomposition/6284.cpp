// https://loj.ac/problem/6284
//
// Calculate how many different elements in a range and calculate the occurrence of a value in a range 
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

constexpr int MAX_BLOCKS = 350;

namespace IO {
template <typename T>
inline void read(T& t) {
    int n = 0;
    int c = getchar_unlocked();
    t = 0;
    while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
    while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
    if (n)
        t = -t;
}
template <typename T, typename... Args>
inline void read(T& t, Args&... args) {
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

namespace SD {
vector<ll> A;
int n;
int blocks;
vector<int> block;
vector<int> L;
vector<int> R;
bitset<MAX_BLOCKS> has_single_weight;
vector<int> single_weight;
bool check_if_block_has_single_weight(int block_id) {
    bool result = true;
    ll val = A.at(L.at(block_id));  // get the first element in the block
    for (int i = L.at(block_id) + 1; i <= R.at(block_id); ++i) {
        if (A.at(i) != val) {
            result = false;
            break;
        }
    }
    return result;
}
void decompose() {
    blocks = sqrt(n);
    L.resize(blocks + 1);
    R.resize(blocks + 1);
    for (int i = 1; i <= blocks; ++i) {
        L.at(i) = (i - 1) * blocks + 1;
        R.at(i) = i * blocks;
    }
    if (R.back() < n) {
        L.emplace_back(R.back() + 1);
        R.emplace_back(n);
        ++blocks;
    }
    block.resize(n + 1);
    for (int i = 1; i <= blocks; ++i) {
        for (int j = L.at(i); j <= R.at(i); ++j) {
            block.at(j) = i;
        }
    }
    single_weight.resize(blocks + 1);
    for (int i = 1; i <= blocks; ++i) {
        if (check_if_block_has_single_weight(i)) {
            has_single_weight[i] = true;
            single_weight.at(i) = A.at(L.at(i));
        }
    }
}
void restore(int block_id) {
    if (has_single_weight[block_id]) {
        for (int i = L.at(block_id); i <= R.at(block_id); ++i) {
            A.at(i) = single_weight.at(block_id);
        }
    }
}
int calculate_and_query(int l, int r, ll c) {
    int l_block = block.at(l);
    int r_block = block.at(r);
    int counter = 0;
    if (l_block == r_block) {
        restore(l_block);
        for (int i = l; i <= r; ++i) {
            if (A.at(i) == c) {
                ++counter;
            } else {
                A.at(i) = c;
            }
        }
        if (check_if_block_has_single_weight(l_block)) {
            has_single_weight[l_block] = true;
            single_weight.at(l_block) = c;
        } else {
            has_single_weight[l_block] = false;
        }
    } else {
        // middle blocks
        for (int i = l_block + 1; i <= r_block - 1; ++i) {
            if (has_single_weight[i]) {
                if (single_weight.at(i) == c) {
                    counter += R.at(i) - L.at(i) + 1;
                } else {
                    single_weight.at(i) = c;
                }
            } else {
                for (int j = L.at(i); j <= R.at(i); ++j) {
                    if (A.at(j) == c) {
                        ++counter;
                    } else {
                        A.at(j) = c;
                    }
                }
                has_single_weight[i] = true;
                single_weight.at(i) = c;
            }
        }
        // leftmost block
        restore(l_block);
        for (int i = l; i <= R.at(l_block); ++i) {
            if (A.at(i) == c) {
                ++counter;
            } else {
                A.at(i) = c;
            }
        }
        if (check_if_block_has_single_weight(l_block)) {
            has_single_weight[l_block] = true;
            single_weight.at(l_block) = c;
        } else {
            has_single_weight[l_block] = false;
        }
        // rightmost block
        restore(r_block);
        for (int i = L.at(r_block); i <= r; ++i) {
            if (A.at(i) == c) {
                ++counter;
            } else {
                A.at(i) = c;
            }
        }
        if (check_if_block_has_single_weight(r_block)) {
            has_single_weight[r_block] = true;
            single_weight.at(r_block) = c;
        } else {
            has_single_weight[r_block] = false;
        }
    }
    return counter;
}
}  // namespace SD

int main() {
    IO::read(SD::n);
    SD::A.resize(SD::n + 1);
    for (int i = 1; i <= SD::n; ++i) {
        IO::read(SD::A.at(i));
    }
    SD::decompose();
    int l, r;
    ll c;
    for (int i = 1; i <= SD::n; ++i) {
        IO::read(l, r, c);
        IO::writeln(SD::calculate_and_query(l, r, c));
    }

    return 0;
}
