#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr int MAXN = 100005;

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar_unlocked(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

template<int N, int D=1>
class FenwickTree {
    vector<int> tree;
    int isum(int ps) {return tree[ps];}
    template<class... T>
    int isum(int ps, int n, T... tail) {
        int a = 0;
        while (n) {
            a += isum(ps*N + n, tail...);
            n -= (n & -n);
        }
        return a;
    }
    void iupd(int u, int ps) {tree[ps] += u;}
    template<class... T>
    void iupd(int u, int ps, int n, T... tail) {
        while (n < N) {
            iupd(u, ps*N + n, tail...);
            n += (n & -n);
        }
    }
public:
    FenwickTree() : tree(pow(N, D)) {}
    template<class... T>
    int sum(T... v) {return isum(0, v...);}
    template<class... T>
    void upd(int u, T... v) {iupd(u, 0, v...);}
};

unordered_map<int, int> indexToNumber;
unordered_map<int, int> numberToIndex;
FenwickTree<MAXN> t;

int main() {

    int n, val;
    IO::read(n);
    for (int i = 1; i <= n; ++i) {
        IO::read(val);
        indexToNumber[i] = val;
        numberToIndex[val] = i;
        t.upd<int>(1, i);
    }
    int l = 1, r = n;
    for (int i = 1; i <= n; ++i) {
        if (i & 1) {
            t.upd(-1, numberToIndex[l]);
            IO::writeln(t.sum(numberToIndex[l]));
            ++l;
        }
        else {
            t.upd(-1, numberToIndex[r]);
            if (numberToIndex[r] == 1) {
                IO::writeln(t.sum<int>(n));
            }
            else {
                IO::writeln(t.sum<int>(n) - t.sum<int>(numberToIndex[r]));
            }
            --r;
        }
    }
    return 0;
}
