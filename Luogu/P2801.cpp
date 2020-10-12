#include <bits/stdc++.h>

using namespace std;
using ll = long long;

namespace IO {
    inline
    void read_alpha(char &t) {
        int c = getchar_unlocked();
        t = 0;
        while (!isalpha(c)) c = getchar_unlocked();
        while (isalpha(c)) t = c, c = getchar_unlocked();
    }
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

namespace SD {
    vector<ll> A;
    vector<ll> Asort;
    vector<ll> add;
    vector<int> block;
    vector<int> L;
    vector<int> R;
    int n;
    int blocks;
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
        add.resize(blocks + 1);
        block.resize(n + 1);
        for (int i = 1; i <= blocks; ++i) {
            for (int j = L.at(i); j <= R.at(i); ++j) {
                block.at(j) = i;
            }
        }
        Asort = A;
        for (int i = 1; i <= blocks; ++i) {
            sort(Asort.begin() + L.at(i), Asort.begin() + R.at(i) + 1);
        }
    }
    inline void resort(int block_id) {
        for (int i = L.at(block_id); i <= R.at(block_id); ++i) {
            Asort.at(i) = A.at(i);
        }
        sort(Asort.begin() + L.at(block_id), Asort.begin() + R.at(block_id) + 1);
    }
    inline void range_add(int l, int r, ll k) {
        int l_block = block.at(l);
        int r_block = block.at(r);
        if (l_block == r_block) {
            for (int i = l; i <= r; ++i) {
                A.at(i) += k;
            }
            resort(l_block);
        } else {
            for (int i = l_block + 1; i <= r_block - 1; ++i) {
                add.at(i) += k;
            }
            for (int i = l; i <= R.at(l_block); ++i) {
                A.at(i) += k;
            }
            resort(l_block);
            for (int i = L.at(r_block); i <= r; ++i) {
                A.at(i) += k;
            }
            resort(r_block);
        }
    }
    inline int count_elements(int l, int r, ll c) {
        int l_block = block.at(l);
        int r_block = block.at(r);
        ll counter = 0;
        if (l_block == r_block) {
            for (int i = l; i <= r; ++i) {
                if (A.at(i) + add.at(l_block) >= c) {
                    ++counter;
                }
            }
        } else {
            for (int i = l_block + 1; i <= r_block - 1; ++i) {
                auto iter0 = Asort.begin() + L.at(i);
                auto iter1 = Asort.begin() + R.at(i) + 1;
                counter += (int)(iter1 - lower_bound(iter0, iter1, c - add.at(i)));
            }
            for (int i = l; i <= R.at(l_block); ++i) {
                if (A.at(i) + add.at(l_block) >= c) {
                    ++counter;
                }
            }
            for (int i = L.at(r_block); i <= r; ++i) {
                if (A.at(i) + add.at(r_block) >= c) {
                    ++counter;
                }
            }
        }
        return counter;
    }
}

int main() {

    int q, l, r;
    ll c;
    char op;
    IO::read(SD::n, q);
    SD::A.resize(SD::n + 1);
    for (int i = 1; i <= SD::n; ++i) {
        IO::read(SD::A.at(i));
    }
    SD::decompose();
    while (q--) {
        IO::read_alpha(op);
        if (op == 'M') {
            IO::read(l, r, c);
            SD::range_add(l, r, c);
        } else {
            IO::read(l, r, c);
            IO::writeln(SD::count_elements(l, r, c));
        }
    }

    return 0;
}