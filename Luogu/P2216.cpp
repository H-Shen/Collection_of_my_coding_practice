#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Bump Allocator
static char buf[450 << 20];
void* operator new(size_t s) {
    static size_t i = sizeof buf;
    assert(s < i);
    return (void*)&buf[i -= s];
}
void operator delete(void*) {}

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

struct SparseTable2D {
    int*** sptMax = nullptr;
    int*** sptMin = nullptr;
    int n, m, logN, log2Size;
    void init(int Size) {
        log2Size = log2(Size);
        logN = floor(log2(max(n, m)) + 2);

        sptMax = new int**[n + 5];
        for (int i = 0; i < n + 5; ++i) {
            sptMax[i] = new int*[m + 5];
            for (int j = 0; j < m + 5; ++j) {
                sptMax[i][j] = new int[logN + 1];
                for (int k = 0; k < logN + 1; ++k) {
                    sptMax[i][j][k] = 0;
                }
            }
        }
        sptMin = new int**[n + 5];
        for (int i = 0; i < n + 5; ++i) {
            sptMin[i] = new int*[m + 5];
            for (int j = 0; j < m + 5; ++j) {
                sptMin[i][j] = new int[logN + 1];
                for (int k = 0; k < logN + 1; ++k) {
                    sptMin[i][j][k] = 0;
                }
            }
        }

    }
    SparseTable2D() = default;
    // input 2d array of n*m elements
    void input() const {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                IO::read(sptMax[i][j][0]);
                sptMin[i][j][0] = sptMax[i][j][0];
            }
        }
    }
    void build() const {
        for (int k = 1; k <= logN; ++k) {
            for (int i = 1; i + (1 << k) - 1 <= n; ++i) {
                for (int j = 1; j + (1 << k) - 1 <= m; ++j) {
                    sptMax[i][j][k] = max({sptMax[i][j][k-1], sptMax[i+(1<<(k-1))][j][k-1], sptMax[i][j+(1<<(k-1))][k-1], sptMax[i+(1<<(k-1))][j+(1<<(k-1))][k-1] });
                    sptMin[i][j][k] = min({sptMin[i][j][k-1], sptMin[i+(1<<(k-1))][j][k-1], sptMin[i][j+(1<<(k-1))][k-1], sptMin[i+(1<<(k-1))][j+(1<<(k-1))][k-1] });
                }
            }
        }
    }

    // Pre: r1 <= r2, c1 <= c2
    int queryMax(int r1, int c1, int r2, int c2) const {
        int s = log2Size;
        return max({sptMax[r1][c1][s], sptMax[r2-(1<<s)+1][c1][s], sptMax[r1][c2-(1<<s)+1][s], sptMax[r2-(1<<s)+1][c2-(1<<s)+1][s]});
    }

    // Pre: r1 <= r2, c1 <= c2
    int queryMin(int r1, int c1, int r2, int c2) const {
        int s = log2Size;
        return min({sptMin[r1][c1][s], sptMin[r2-(1<<s)+1][c1][s], sptMin[r1][c2-(1<<s)+1][s], sptMin[r2-(1<<s)+1][c2-(1<<s)+1][s]});
    }
};

SparseTable2D st;
int a, b, n;

int main() {

    IO::read(a, b, n);
    st.n = a;
    st.m = b;
    st.init(n);
    st.input();
    st.build();

    int diff = numeric_limits<int>::max();
    for (int i = 1; i + n - 1 <= a; ++i) {
        for (int j = 1; j + n - 1 <= b; ++j) {
            diff = min(diff, abs(st.queryMin(i, j, i + n - 1, j + n - 1) - st.queryMax(i, j, i + n - 1, j + n - 1)));
        }
    }
    IO::writeln(diff);
    return 0;
}