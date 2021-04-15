#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

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

int** stMin;
int* Log2;

void pre(int N, const vector<int> &A) {
    Log2 = new int[N + 1];
    Log2[1] = 0;
    Log2[2] = 1;
    for (int i = 3; i <= N; ++i) {
        Log2[i] = Log2[i / 2] + 1;
    }
    int k = Log2[N] + 1;
    stMin = new int*[N + 1];
    for (int i = 0; i <= N; ++i) {
        stMin[i] = new int[k + 1];
        for (int j = 0; j <= k; ++j) {
            stMin[i][j] = 0;
        }
    }
    for (int i = 0; i < N; ++i) {
        stMin[i][0] = A[i];
    }
    for (int j = 1; j <= k; ++j) {
        for (int i = 0; i+(1<<j) <= N; ++i) {
            stMin[i][j] = min(stMin[i][j-1], stMin[i + (1 << (j - 1))][j - 1]);
        }
    }
}

// Get the minimum value in the range [l,r] of the array A
int getMin(int l, int r) {
    int j = Log2[r-l+1];
    return min(stMin[l][j], stMin[r - (1 << j) + 1][j]);
}

int main() {

    int m, n, l, r;
    IO::read(m, n);
    vector<int> A(m);
    for (auto &i : A) IO::read(i);
    pre(m, A);
    bool firstItem = true;
    while (n--) {
        IO::read(l, r);
        --l; --r;
        if (firstItem) {
            firstItem = false;
        } else {
            putchar_unlocked(' ');
        }
        IO::write(getMin(l, r));
    }
    putchar_unlocked('\n');

    return 0;
}