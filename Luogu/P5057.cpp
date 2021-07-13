#include <bits/stdc++.h>

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

struct SegmentTree {
    // max: INF = numeric_limits<int>::min();
    // min: INF = numeric_limits<int>::max();
    static const int INF = numeric_limits<int>::min();
    vector<int> st, lz;
    int n;
    void build(int p, int l, int r, const vector<int> &A) {
        if (l == r) { st[p] = A[l]; return; }
        build(2*p, l, (l+r)/2, A);
        build(2*p+1, (l+r)/2+1, r, A);
        st[p] = max(st[2*p], st[2*p+1]); // RMQ -> min/max, RSQ -> +
    }
    SegmentTree() = default;
    SegmentTree(vector<int> &A) {
        n = (int)A.size();
        st.resize(n << 2);
        lz.resize(n << 2);
        // The p is id of the tree, which starts from root = 1
        build(1, 0, n - 1, A);
    }
    void push(int p, int l, int r) {
        if (lz[p]) {
            st[p] += lz[p];
            // RMQ -> add: = lz[p],         increment: += lz[p]
            // RSQ -> add: = (r-l+1)*lz[p], increment: += (r-l+1)*lz[p]
            if(l!=r)
            {
                lz[2*p+1] += lz[p];
                lz[2*p] += lz[p];
            }
            lz[p] = 0;
        }
    }
    int query(int p, int l, int r, int i, int j) {
        push(p, l, r);
        if (r < i or l > j) return INF; // RMQ -> INF, RSQ -> 0
        if (l >= i and r <= j) return st[p];
        return max(query(2*p, l, (l+r)/2, i, j),
                   query(2*p+1, (l+r)/2+1, r, i, j));
        // RMQ -> min/max, RSQ -> +
    }
    void update(int p, int l, int r, int i, int j, int v) {
        push(p, l, r);
        if (r < i or l > j) return;
        if (l >= i and r <= j) { lz[p] = v; push(p, l, r); return; }
        update(2*p, l, (l+r)/2, i, j, v);
        update(2*p+1, (l+r)/2+1, r, i, j, v);
        st[p] = max(st[2*p], st[2*p+1]); // RMQ -> min/max, RSQ -> +
    }
};

int n, m, t, l, r, val;
SegmentTree st;
vector<int> A;

int main() {

    IO::read(n,m);
    A.resize(n);
    st.n = n;
    st.st.resize(n << 2);
    st.lz.resize(n << 2);
    st.build(1, 0, n - 1, A);
    while (m--) {
        IO::read(t);
        if (t == 1) {
            IO::read(l, r);
            --l;
            --r;
            st.update(1, 0, st.n - 1, l, r, 1);
        }
        else {
            IO::read(l);
            --l;
            val = st.query(1, 0, st.n - 1, l, l);
            if (val & 1) {
                IO::writeln(1);
            }
            else {
                IO::writeln(0);
            }
        }
    }
    return 0;
}