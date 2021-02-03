// https://open.kattis.com/problems/inquiryi

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

int n;
vector<ll> A, suffixSum;

int main() {

    IO::read(n);
    A.resize(n);
    for (auto &i : A) IO::read(i);
    suffixSum.resize(n);
    suffixSum.at(0) = A.at(n - 1);
    for (int i = 1; i < n; ++i) {
        suffixSum.at(i) = suffixSum.at(i - 1) + A.at(n - i - 1);
    }
    ll maxValue = -1;
    ll left = 0;
    ll right;
    for (int i = 0; i < n - 1; ++i) {
        left += A.at(i) * A.at(i);
        right = suffixSum.at(n - 2 - i);
        maxValue = max(maxValue, left * right);
    }
    IO::writeln(maxValue);

    return 0;
}
