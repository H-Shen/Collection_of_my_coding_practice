#include <bits/extc++.h>

using namespace std;
using ll = long long;

namespace IO {
    template<typename T>
    inline
    bool can_read(T &t) {
        int n = 0;
        int ch = getchar_unlocked();
        while (!isdigit(ch)) {
            if (ch == EOF) return false;
            n |= ch == '-';
            ch = getchar_unlocked();
        }
        t = 0;
        while (isdigit(ch)) {
            t = t * 10 + ch - 48;
            ch = getchar_unlocked();
        }
        if (n) t = -t;
        return true;
    }

    template<typename T, typename... Args>
    inline
    bool can_read(T &t, Args &... args) {
        return can_read(t) && can_read(args...);
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

template<typename T>
struct BIT {
    vector<T> t1, t2;
    int N;
    int lowbit(int i) {
        return i & (-i);
    }
    // index starts from 1
    BIT(int n) : N(n+1) {
        t1.resize(N);
        t2.resize(N);
    }
    T sum(const vector<T> &t, int n) {
        T a(0);
        while (n) {
            a += t[n];
            n -= lowbit(n);
        }
        return a;
    }
    T rsum(int n) {
        return sum(t1,n)*n-sum(t2,n);
    }
    T rsum(int l, int r) {
        return rsum(r)-rsum(l-1);
    }
    void upd(vector<T> &t, int n, T val) {
        while (n < N) {
            t[n] += val;
            n += lowbit(n);
        }
    }
    void rupd(int l, int r, T val) {
        upd(t1,l,val);
        upd(t1,r+1,-val);
        upd(t2,l,val*(l-1));
        upd(t2,r+1,-val*r);
    }
};

int main() {

    int n, m, val;
    IO::read(n, m);
    BIT<ll> bit(n);
    for (int i = 1; i <= n; ++i) {
        IO::read(val);
        bit.rupd(i,i,val);
    }
    int op, x, y, k;
    while (m--) {
        IO::read(op);
        if (op == 1) {
            IO::read(x,y,k);
            bit.rupd(x,y,k);
        }
        else {
            IO::read(x);
            IO::writeln(bit.rsum(x,x));
        }
    }
    return 0;
}