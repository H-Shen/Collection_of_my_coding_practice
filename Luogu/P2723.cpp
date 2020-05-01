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

vector<ll> factors;
vector<int> countIndex;
vector<ll> dp;

int main() {

    int k, n;
    IO::read(k, n);
    factors.resize(k);
    for (auto &i : factors) IO::read(i);
    if (n == 1) {
        putchar_unlocked('1');
        return 0;
    }
    countIndex.resize(k, 0);
    dp.resize(n + 1, 0);
    dp.at(0) = 1;
    ll minVal;
    for (int i = 1; i <= n; ++i) {
        minVal = numeric_limits<ll>::max();
        for (int j = 0; j < k; ++j) {
            minVal = min(minVal, dp.at(countIndex.at(j)) * factors.at(j));
        }
        dp.at(i) = minVal;
        for (int j = 0; j < k; ++j) {
            if (dp.at(i) == dp.at(countIndex.at(j)) * factors.at(j)) {
                ++countIndex.at(j);
            }
        }
    }
    IO::writeln(dp.at(n));
    return 0;
}
