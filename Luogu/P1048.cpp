#include <bits/stdc++.h>

using namespace std;
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

unordered_map<int, unordered_map<int,int> > dp;
int m, t;
vector<int> timeCost, value;

int solve(int pos, int remaining_time) {
    if (pos >= m) {
        return 0;
    }
    if (dp.find(pos) != dp.end() && dp[pos].find(remaining_time) != dp[pos].end()) {
        return dp[pos][remaining_time];
    }
    int dontTakeCurrent = solve(pos+1,remaining_time);
    int takeCurrent = numeric_limits<int>::min();
    if (remaining_time >= timeCost[pos]) {
        takeCurrent = solve(pos+1,remaining_time-timeCost[pos]) + value[pos];
    }
    dp[pos][remaining_time] = max(dontTakeCurrent, takeCurrent);
    return dp[pos][remaining_time];
}

int main() {

    IO::read(t, m);
    timeCost.resize(m);
    value.resize(m);
    for (int i = 0; i < m; ++i) {
        IO::read(timeCost[i], value[i]);
    }
    int maxValue = 0;
    for (int i = 0; i < m; ++i) {
        maxValue = max(maxValue, solve(i,t));
    }
    IO::writeln(maxValue);

    return 0;
}