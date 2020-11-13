#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

namespace IO {
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

constexpr int STEPS = 4;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int r, c;
vector<vector<int> > M, dp;

int f(int i, int j) {
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int new_i, new_j;
    vector<int> temp;
    for (int step = 0; step < STEPS; ++step) {
        new_i = i + dx[step];
        new_j = j + dy[step];
        if (new_i >= 0 && new_i < r && new_j >= 0 && new_j < c && M[new_i][new_j] > M[i][j]) {
            temp.emplace_back(f(new_i, new_j));
        }
    }
    if (temp.empty()) {
        dp[i][j] = 1;
    } else {
        dp[i][j] = *max_element(temp.begin(), temp.end()) + 1;
    }
    return dp[i][j];
}

int main() {

    IO::read(r, c);
    M.resize(r, vector<int>(c));
    dp.resize(r, vector<int>(c, -1));

    for (auto &i : M) {
        for (auto &j : i) {
            IO::read(j);
        }
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            dp[i][j] = f(i, j);
        }
    }

    int max_length = -1;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            max_length = max(max_length, dp[i][j]);
        }
    }
    IO::writeln(max_length);

    return 0;
}