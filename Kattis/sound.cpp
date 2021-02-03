// https://open.kattis.com/problems/sound

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

vector<vector<ll> > sptMax, sptMin;
vector<ll> Log2;
int n, logn;

void init() {
    Log2.resize(n + 5);
    Log2[1] = 0;
    Log2[2] = 1;
    for (int i = 3; i < n + 5; ++i)
        Log2[i] = Log2[i >> 1] + 1;
    logn = floor(log2(n) + 2);
    sptMax.resize(n + 5, vector<ll>(logn));
    sptMin.resize(n + 5, vector<ll>(logn));
}

void input() {
    for (int i = 1; i <= n; ++i) {
        cin >> sptMax[i][0];
        sptMin[i][0] = sptMax[i][0];
    }
}

void build() {
    for (int j = 1; j <= logn; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
            sptMax[i][j] = max(sptMax[i][j - 1], sptMax[i + (1 << (j - 1))][j - 1]);
            sptMin[i][j] = min(sptMin[i][j-1],sptMin[i+(1<<(j-1))][j-1]);
        }
}

ll queryMax(int l, int r) {
    int s = Log2[r-l+1];
    ll ans = max(sptMax[l][s], sptMax[r-(1<<s)+1][s]);
    return ans;
}

ll queryMin(int l, int r) {
    int s = Log2[r-l+1];
    ll ans = min(sptMin[l][s], sptMin[r-(1<<s)+1][s]);
    return ans;
}

int m;
ll c;

int main() {

    IO::read(n, m, c);
    init();
    input();
    build();

    int lower_i = 1;
    int upper_i = n - m + 1;
    if (upper_i < lower_i) {
        puts("NONE");
        return 0;
    }
    bool haveAns = false;
    for (int i = lower_i; i <= upper_i; ++i) {
        if (queryMax(i, i + m - 1) - queryMin(i, i + m - 1) <= c) {
            haveAns = true;
            IO::writeln(i);
        }
    }
    if (!haveAns) {
        puts("NONE");
    }


    return 0;
}
