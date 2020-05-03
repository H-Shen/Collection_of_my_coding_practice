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

vector<pair<int, int> > transitions = {
        {-2, +1},
        {-1, +2},
        {+1, +2},
        {+2, +1}
};

int n, m;
int ways = 0;
void dfs(int i, int j) {
    // From the sample given, we can conclude the n is the index of row
    // and m is the index of column.
    if (i == n && j == m) {
        ++ways;
        return;
    }
    int new_i, new_j;
    for (const auto &[step_i, step_j] : transitions) {
        new_i = i + step_i;
        new_j = j + step_j;
        if (new_i >= 0 && new_i <= n && new_j >= 0 && new_j <= m) {
            dfs(new_i, new_j);
        }
    }
}

int main() {
    IO::read(n, m);
    dfs(0, 0);
    IO::writeln(ways);
    return 0;
}