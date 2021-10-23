// https://open.kattis.com/problems/fluortanten

#include <bits/extc++.h>

using namespace std;
using ll = long long;

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar('\n');
    }
}

int n, pos;
deque<ll> dq;

int main() {
    IO::read(n);
    dq.resize(n);
    for (int i = 0; i < n; ++i) {
        IO::read(dq[i]);
        if (dq[i] == 0) {
            pos = i;
        }
    }
    dq.erase(dq.begin() + pos);
    dq.push_front(0);
    dq.push_front(0);
    ll left = 0;
    ll right = 0;
    for (ll i = 2; i <= n; ++i) {
        right += dq[i] * i;
    }
    ll maxVal = numeric_limits<ll>::min();
    maxVal = max(maxVal, left+right);
    for (ll i = 2; i <= n; ++i) {
        left += dq[i] * (i - 1);
        right -= dq[i] * i;
        maxVal = max(maxVal, left+right);
    }
    IO::writeln(maxVal);
    return 0;
}
