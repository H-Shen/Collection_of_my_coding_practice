#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

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
    int n;
    int blocks;
    vector<int> A;
    vector<int> block;
    vector<int> sum;
    vector<bool> flag;
    vector<int> L;
    vector<int> R;
    inline void decompose() {
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
        sum.resize(blocks + 1);
        flag.resize(n + 1, true);
        block.resize(n + 1);
        for (int i = 1; i <= blocks; ++i) {
            for (int j = L.at(i); j <= R.at(i); ++j) {
                block.at(j) = i;
            }
        }
    }
    inline void restore(int block_id) {
        if (flag.at(block_id)) return;
        sum.at(block_id) = R.at(block_id) - L.at(block_id) + 1 - sum.at(block_id);
        for (int i = L.at(block_id); i <= R.at(block_id); ++i) {
            if (A.at(i) == 0) {
                A.at(i) = 1;
            } else {
                A.at(i) = 0;
            }
        }
        flag.at(block_id) = true;
    }
    inline void range_switch(int l, int r) {
        int l_block = block.at(l);
        int r_block = block.at(r);
        if (l_block == r_block) {
            restore(l_block);
            for (int i = l; i <= r; ++i) {
                sum.at(l_block) -= A.at(i);
                if (A.at(i) == 0) {
                    A.at(i) = 1;
                } else {
                    A.at(i) = 0;
                }
                sum.at(l_block) += A.at(i);
            }
        } else {
            for (int i = l_block + 1; i <= r_block - 1; ++i) {
                if (flag.at(i)) {
                    flag.at(i) = false;
                } else {
                    flag.at(i) = true;
                }
            }
            restore(l_block);
            for (int i = l; i <= R.at(l_block); ++i) {
                sum.at(l_block) -= A.at(i);
                if (A.at(i) == 0) {
                    A.at(i) = 1;
                } else {
                    A.at(i) = 0;
                }
                sum.at(l_block) += A.at(i);
            }
            restore(r_block);
            for (int i = L.at(r_block); i <= r; ++i) {
                sum.at(r_block) -= A.at(i);
                if (A.at(i) == 0) {
                    A.at(i) = 1;
                } else {
                    A.at(i) = 0;
                }
                sum.at(r_block) += A.at(i);
            }
        }
    }
    inline int get_sum(int block_id) {
        if (flag.at(block_id)) {
            return sum.at(block_id);
        }
        return R.at(block_id) - L.at(block_id) + 1 - sum.at(block_id);
    }
    inline int range_sum(int l, int r) {
        int l_block = block.at(l);
        int r_block = block.at(r);
        int result = 0;
        if (l_block == r_block) {
            for (int i = l; i <= r; ++i) {
                if (flag.at(l_block)) {
                    result += A.at(i);
                } else {
                    if (A.at(i) == 0) {
                        result += 1;
                    }
                }
            }
        } else {
            for (int i = l_block + 1; i <= r_block - 1; ++i) {
                result += get_sum(i);
            }
            for (int i = l; i <= R.at(l_block); ++i) {
                if (flag.at(l_block)) {
                    result += A.at(i);
                } else {
                    if (A.at(i) == 0) {
                        result += 1;
                    }
                }
            }
            for (int i = L.at(r_block); i <= r; ++i) {
                if (flag.at(r_block)) {
                    result += A.at(i);
                } else {
                    if (A.at(i) == 0) {
                        result += 1;
                    }
                }
            }
        }
        return result;
    }
}

int main() {

    int m;
    IO::read(SD::n, m);
    SD::A.resize(SD::n + 1, 0);
    SD::decompose();
    int op, x, y;
    while (m--) {
        IO::read(op);
        if (op == 0) {
            IO::read(x, y);
            SD::range_switch(x, y);
        } else {
            IO::read(x, y);
            IO::writeln(SD::range_sum(x, y));
        }
    }

    return 0;
}