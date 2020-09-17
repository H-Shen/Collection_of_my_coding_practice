// https://open.kattis.com/problems/city
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

ll n, d;
vector<ll> H;
vector<ll> E;
vector<ll> a, b;

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

auto f = [](ll hp) -> ll{
    if (hp >= 0) {
        return (hp + d - 1) / d;
    }
    return 0;
};

ll solve(int i, int m) {
    if (m != 0) {
        if (a.at(i) != -1) {
            return a.at(i);
        }
    } else {
        if (b.at(i) != -1) {
            return b.at(i);
        }
    }
    if (n - 1 == i) {
        if (m != 0) {
            return f(H.at(i) - E.at(i - 1));
        }
        return f(H.at(i));
    }
    if (m != 0) {
        ll left = f(H.at(i) - E.at(i - 1)) + solve(i + 1, 1);
        ll right = f(H.at(i) - E.at(i - 1) - E.at(i + 1)) + solve(i + 1, 0);
        a.at(i) = min(left, right);
        return a.at(i);
    }
    ll left = f(H.at(i)) + solve(i + 1, 1);
    ll right = f(H.at(i) - E.at(i + 1)) + solve(i + 1, 0);
    b.at(i) = min(left, right);
    return b.at(i);
}

int main() {

    int t;
    IO::read(t);
    while (t--) {
        IO::read(n, d);
        // reset
        vector<ll>().swap(H);
        H.resize(n);
        for (auto &i : H) IO::read(i);
        vector<ll>().swap(E);
        E.resize(n);
        for (auto &i : E) IO::read(i);
        vector<ll>().swap(a);
        a.resize(n, -1);
        vector<ll>().swap(b);
        b.resize(n, -1);
        IO::writeln(solve(0, 0));
    }

    return 0;
}
