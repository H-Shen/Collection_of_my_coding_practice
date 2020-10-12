#include <bits/stdc++.h>

using namespace std;
using ll = long long;

namespace IO {
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
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
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar('\n');
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
    inline void update(int l, ll v) {
        A.at(l) = v;
        int l_block = block.at(l);
        resort(l_block);
    }
    inline int count_elements(int l, int r, ll v) {
        int l_block = block.at(l);
        int r_block = block.at(r);
        int counter = 0;
        if (l_block == r_block) {
            for (int i = l; i <= r; ++i) {
                if (A.at(i) + add.at(l_block) < v) {
                    ++counter;
                }
            }
        } else {
            for (int i = l_block + 1; i <= r_block - 1; ++i) {
                auto iter0 = Asort.begin() + L.at(i);
                auto iter1 = Asort.begin() + R.at(i) + 1;
                counter += (int)(lower_bound(iter0, iter1, v - add.at(i)) - iter0);
            }
            for (int i = l; i <= R.at(l_block); ++i) {
                if (A.at(i) + add.at(l_block) < v) {
                    ++counter;
                }
            }
            for (int i = L.at(r_block); i <= r; ++i) {
                if (A.at(i) + add.at(r_block) < v) {
                    ++counter;
                }
            }
        }
        return counter;
    }
}

int main() {

    int m;
    ll u;
    IO::read(SD::n, m, u);
    SD::A.resize(SD::n + 1);
    for (int i = 1; i <= SD::n; ++i) {
        IO::read(SD::A.at(i));
    }
    SD::decompose();
    int l, r, p;
    ll v;
    int k;
    while (m--) {
        IO::read(l, r, v, p);
        k = SD::count_elements(l, r, v);
        SD::update(p, u * k / (r - l + 1));
    }
    for (int i = 1; i <= SD::n; ++i) {
        IO::writeln(SD::A.at(i) + SD::add.at(SD::block.at(i)));
    }

    return 0;
}