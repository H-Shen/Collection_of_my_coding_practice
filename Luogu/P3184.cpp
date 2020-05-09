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

vector<ll> A;

int main() {

    int n, q;
    ll val;
    IO::read(n, q);
    while (n--) {
        IO::read(val);
        A.emplace_back(val);
    }
    sort(A.begin(), A.end());
    ll a, b;
    ll minVal = A.front();
    ll maxVal = A.back();
    while (q--) {
        IO::read(a, b);
        // Case 1: out of range
        if (b < minVal || a > maxVal) {
            IO::writeln(0);
            continue;
        }
        if (b > maxVal) {
            b = maxVal;
        }
        if (a < minVal) {
            a = minVal;
        }
        auto iter1 = lower_bound(A.begin(), A.end(), a);
        auto iter2 = lower_bound(A.begin(), A.end(), b);
        if (*iter2 != b) {
            --iter2;
        }
        IO::writeln(iter2 - iter1 + 1);
    }
    return 0;
}