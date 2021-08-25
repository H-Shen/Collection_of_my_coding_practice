// https://open.kattis.com/problems/findmyfamily

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
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

int n, m;
vector<int> ans;
bool haveAns;

int main() {
    IO::read(n);
    for (int kase = 1; kase <= n; ++kase) {
        IO::read(m);
        vector<int> A(m);
        haveAns = false;
        vector<int> maxFromRight(m);
        for (auto &i : A) IO::read(i);
        maxFromRight[m-1] = A[m-1];
        for (int i = m - 2; i >= 0; --i) {
            maxFromRight[i] = max(A[i], maxFromRight[i+1]);
        }
        set<int> s;
        for (int i = 0; i <= m-3; ++i) {
            s.insert(A[i]);
            auto iter = s.upper_bound(A[i+1]);
            if (iter != s.end() && maxFromRight[i+2] > *iter && maxFromRight[i+2] > A[i+1]) {
                haveAns = true;
                break;
            }
        }
        if (haveAns) {
            ans.emplace_back(kase);
        }
    }
    IO::writeln(ans.size());
    for (const auto &i : ans) {
        IO::writeln(i);
    }
    return 0;
}
