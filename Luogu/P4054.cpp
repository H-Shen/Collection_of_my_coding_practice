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

string add(string a, string b) {
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    size_t maxSize = max(a.size(), b.size());
    while (a.size() != maxSize) a.push_back('0');
    while (b.size() != maxSize) b.push_back('0');
    string sum(maxSize+1,0);
    for (size_t i = 0; i != maxSize; ++i) {
        sum[i] += (a[i] - '0') + (b[i] - '0');
        if (sum[i] >= 10) {
            ++sum[i+1];
            sum[i] -= 10;
        }
    }
    for (size_t i = 0; i != maxSize+1; ++i) {
        sum[i] += '0';
    }
    while (sum.size() > 2 && sum.back() == '0') sum.pop_back();
    reverse(sum.begin(), sum.end());
    return sum;
}

template<typename T>
struct BIT_2D {
    vector<vector<T> > t;
    T lowbit(T i) {
        return i & (-i);
    }
    int N, M;
    // index starts from 1
    BIT_2D() = default;
    BIT_2D(int n, int m) : N(n), M(m) {
        t.resize(N+1, vector<T>(M+1));
    }
    // add 'val'
    void upd(int x, int y, T val) {
        for (int i = x; i <= N; i += lowbit(i)) {
            for (int j = y; j <= M; j += lowbit(j)) {
                t[i][j] += val;
            }
        }
    }
    void rupd(int x1, int y1, int x2, int y2, T val) {
        upd(x1, y1, val);
        upd(x1, y2+1, -val);
        upd(x2, y1+1, -val);
        upd(x2+1, y2+1, val);
    }
    // rangesum from [1][1] to [x][y]
    T sum(int x, int y) {
        T ans(0);
        for (int i = x; i > 0; i -= lowbit(i)) {
            for (int j = y; j > 0; j -= lowbit(j)) {
                ans += t[i][j];
            }
        }
        return ans;
    }
    T rsum(int x1, int y1, int x2, int y2) {
        return sum(x2,y2)-sum(x2,y1-1)-sum(x1-1,y2)+sum(x1-1,y1-1);
    }
};

constexpr int COLORS = 105;
BIT_2D<int> v[COLORS];
vector<vector<int> > mat;

int main() {

    int n, m;
    int op, x, y, c, x1, x2, y1, y2;
    IO::read(n, m);
    mat.resize(n+1, vector<int>(m+1));
    for (auto & i : v) {
        i.N = n;
        i.M = m;
        i.t.resize(n+1);
        for (auto &j : i.t) {
            j.resize(m+1);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            IO::read(c);
            v[c].upd(i,j,1);    // 1: weight
            mat[i][j] = c;
        }
    }
    int q;
    IO::read(q);
    while (q--) {
        IO::read(op);
        if (op == 1) {
            IO::read(x, y, c);
            if (mat[x][y] == c) continue;
            else {
                v[mat[x][y]].upd(x,y,-1);
                mat[x][y] = c;
                v[mat[x][y]].upd(x,y,1);
            }
        }
        else {
            IO::read(x1,x2,y1,y2,c);
            IO::writeln(v[c].rsum(x1,y1,x2,y2));
        }
    }

    return 0;
}