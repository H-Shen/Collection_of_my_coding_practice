#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
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

namespace SD {
    vector<ll> A;
    int n;
    int blocks;
    vector<int> block, L, R;
    vector<ll> sum, add;

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
        sum.resize(blocks + 1);
        for (int i = 1; i <= blocks; ++i) {
            for (int j = L.at(i); j <= R.at(i); ++j) {
                sum.at(i) += A.at(j);
                block.at(j) = i;
            }
        }
        add.resize(blocks + 1);
    }

    void update(ll k) {
        sum.at(1) += k;
        A.at(1) += k;
    }

    ll get() {
        return A.at(1) + add.at(1);
    }

    void range_add(int l, int r, ll k) {
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

    ll range_sum(int l, int r) {
        int l_block = block.at(l);
        int r_block = block.at(r);
        ll result = 0;
        if (l_block == r_block) {
            for (int i = l; i <= r; ++i) {
                result += A.at(i) + add.at(l_block);
            }
        } else {
            for (int i = l_block + 1; i <= r_block - 1; ++i) {
                result += sum.at(i) + (R.at(i) - L.at(i) + 1) * add.at(i);
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
}

int main() {

    int f;
    IO::read(SD::n, f);
    SD::A.resize(SD::n + 1);
    for (int i = 1; i <= SD::n; ++i) {
        IO::read(SD::A.at(i));
    }
    SD::decompose();
    int op, l, r;
    ll k;
    while (f--) {
        IO::read(op);
        switch (op) {
            case 1:
                IO::read(l, r, k);
                SD::range_add(l, r, k);
                break;
            case 2:
                IO::read(k);
                SD::update(k);
                break;
            case 3:
                IO::read(k);
                SD::update(-k);
                break;
            case 4:
                IO::read(l, r);
                IO::writeln(SD::range_sum(l, r));
                break;
            default:
                IO::writeln(SD::get());
                break;
        }
    }

    return 0;
}