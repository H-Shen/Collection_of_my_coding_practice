// https://open.kattis.com/problems/ballotboxes

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

constexpr int MAXN = 500005;
int city[MAXN];
int n, b, maxPeople, l, r, mid, ans;

// every ballet box can serve x people at most
// check if x <= b
bool check(int x) {
    int counter = 0;
    for (int i = 0; i < n; ++i) {
        counter += city[i] / x;
        if (city[i] % x != 0) {
            ++counter;
        }
    }
    return counter <= b;
}

int main() {
    while (true) {
        IO::read(n, b);
        if (n == -1 && b == -1) break;
        memset(city, 0, sizeof city);
        maxPeople = 0;
        for (int i = 0; i < n; ++i) {
            IO::read(city[i]);
            maxPeople = max(maxPeople, city[i]);
        }
        l = 0;
        r = maxPeople;
        ans = numeric_limits<int>::max();
        while (l <= r) {
            mid = l + ((r-l)>>1);
            if (check(mid)) {
                ans = min(ans, mid);    // lower bound
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        IO::writeln(ans);
    }
    return 0;
}
