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

namespace SQRD {
    vector<ll> A;
    vector<bool> flag;  // true: every element in this block is 0/1 false: otherwise
    vector<int> block;
    int n, blocks;
    vector<ll> sum;
    vector<int> L;
    vector<int> R;
    inline void decompose() {
        blocks = sqrt(n);
        L.resize(blocks + 1);
        R.resize(blocks + 1);
        sum.resize(blocks + 1);
        flag.resize(blocks + 1, true);
        for (int i = 1; i <= blocks; ++i) {
            L.at(i) = (i - 1) * blocks + 1;
            R.at(i) = i * blocks;
        }
        if (R.back() < n) {
            L.emplace_back(R.back() + 1);
            R.emplace_back(n);
            sum.emplace_back(0);
            flag.emplace_back(true);
            ++blocks;
        }
        for (int i = 1; i <= blocks; ++i) {
            for (int j = L.at(i); j <= R.at(i); ++j) {
                block.at(j) = i;
                sum.at(i) += A.at(j);
                if (A.at(j) > 1) {
                    flag.at(i) = false;
                }
            }
        }
    }
    inline void range_sqrt(int l, int r) {
        int l_block = block.at(l);
        int r_block = block.at(r);
        if (l_block == r_block) {
            if (flag.at(l_block)) {
                return;
            }
            for (int i = l; i <= r; ++i) {
                // Ignore all numbers <= 1
                if (A.at(i) <= 1) {
                    continue;
                }
                sum.at(l_block) -= A.at(i);
                A.at(i) = sqrt(A.at(i));
                sum.at(l_block) += A.at(i);
            }
            flag.at(l_block) = true;
            for (int i = L.at(l_block); i <= R.at(l_block); ++i) {
                if (A.at(i) > 1) {
                    flag.at(l_block) = false;
                    break;
                }
            }
        } else {
            for (int i = l_block + 1; i <= r_block - 1; ++i) {
                if (flag.at(i)) {
                    continue;
                }
                flag.at(i) = true;
                for (int j = L.at(i); j <= R.at(i); ++j) {
                    // Ignore all numbers <= 1
                    if (A.at(j) <= 1) {
                        continue;
                    }
                    sum.at(i) -= A.at(j);
                    A.at(j) = sqrt(A.at(j));
                    sum.at(i) += A.at(j);
                    if (A.at(j) > 1) {
                        flag.at(i) = false;
                    }
                }
            }
            for (int i = l; i <= R.at(l_block); ++i) {
                // Ignore all numbers <= 1
                if (A.at(i) <= 1) {
                    continue;
                }
                sum.at(l_block) -= A.at(i);
                A.at(i) = sqrt(A.at(i));
                sum.at(l_block) += A.at(i);
            }
            // recheck
            flag.at(l_block) = true;
            for (int i = L.at(l_block); i <= R.at(l_block); ++i) {
                if (A.at(i) > 1) {
                    flag.at(l_block) = false;
                    break;
                }
            }
            for (int i = L.at(r_block); i <= r; ++i) {
                // Ignore all numbers <= 1
                if (A.at(i) <= 1) {
                    continue;
                }
                sum.at(r_block) -= A.at(i);
                A.at(i) = sqrt(A.at(i));
                sum.at(r_block) += A.at(i);
            }
            // recheck
            flag.at(r_block) = true;
            for (int i = L.at(r_block); i <= R.at(r_block); ++i) {
                if (A.at(i) > 1) {
                    flag.at(r_block) = false;
                    break;
                }
            }
        }
    }
    inline ll range_sum(int l, int r) {
        int l_block = block.at(l);
        int r_block = block.at(r);
        ll result = 0;
        if (l_block == r_block) {
            for (int i = l; i <= r; ++i) {
                result += A.at(i);
            }
        } else {
            for (int i = l_block + 1; i <= r_block - 1; ++i) {
                result += sum.at(i);
            }
            for (int i = l; i <= R.at(l_block); ++i) {
                result += A.at(i);
            }
            for (int i = L.at(r_block); i <= r; ++i) {
                result += A.at(i);
            }
        }
        return result;
    }
}

int main() {

    IO::read(SQRD::n);
    SQRD::A.resize(SQRD::n + 1);
    SQRD::block.resize(SQRD::n + 1);
    for (int i = 1; i <= SQRD::n; ++i) {
        IO::read(SQRD::A.at(i));
    }
    SQRD::decompose();
    int opt, l, r, query;
    ll c;
    IO::read(query);
    for (int i = 1; i <= query; ++i) {
        IO::read(opt, l, r);
        if (l > r) swap(l, r);
        if (opt == 0) {
            SQRD::range_sqrt(l, r);
        } else {
            IO::writeln(SQRD::range_sum(l, r));
        }
    }
    return 0;
}