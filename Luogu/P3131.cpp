#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr ll MOD = 7;

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

vector<ll> A, pre;
vector<vector<int> > stats;

// a%7 == b%7 <=> (a-b)%7
// pre[a]%7 == pre[b]%7 <=> pre[a-b]%7 => maxLength = max(a) - min(b)
int main() {

    int n;
    IO::read(n);
    A.resize(n);
    pre.resize(n);
    for (auto &i : A) IO::read(i);
    partial_sum(A.begin(), A.end(), pre.begin());
    stats.resize(MOD);
    for (int i = 0; i < n; ++i) {
        stats.at(pre.at(i) % MOD).emplace_back(i);
    }
    int maxLength = 0;
    for (const auto &i : stats) {
        if (i.size() > 1) {
            maxLength = max(maxLength, i.back() - i.front());
        }
    }
    IO::writeln(maxLength);

    return 0;
}