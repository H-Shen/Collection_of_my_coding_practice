#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

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

set<ll> A;

int main() {

    int n;
    ll val;
    IO::read(n);
    if (n == 0) {
        IO::writeln(0);
    } else if (n == 1) {
        IO::read(val);
        IO::writeln(val);
    } else {
        ll minVal = numeric_limits<ll>::max();
        ll maxVal = numeric_limits<ll>::min();
        IO::read(val);
        minVal = min(minVal, val);
        maxVal = max(maxVal, val);
        ll sum = val;
        A.insert(val);
        --n;
        for (int i = 0; i < n; ++i) {
            IO::read(val);
            minVal = min(minVal, val);
            maxVal = max(maxVal, val);
            if (val <= minVal) {
                sum += abs(*A.cbegin() - val);
            } else if (val >= maxVal) {
                sum += abs(*A.crbegin() - val);
            } else {
                auto iter = A.lower_bound(val);
                ll right = *iter;
                --iter;
                ll left = *iter;
                sum += min(abs(left - val), abs(right - val));
            }
            A.insert(val);
        }
        IO::writeln(sum);
    }

    return 0;
}