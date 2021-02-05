#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
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

int main() {

    constexpr int MAXN = 120;
    int L, H, K, l, h, a, b;
    IO::read(L, H, K);
    vector<vector<char> > M(MAXN, vector<char>(MAXN, '_'));
    char ch;
    for (int i = 0; i < K; ++i) {
        ch = (char)('a' + i);
        IO::read(l, h, a, b);
        for (int j = b; j < h + b; ++j) {
            for (int k = a; k < l + a; ++k) {
                M.at(j).at(k) = ch;
            }
        }
    }
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < L; ++j) {
            cout << M.at(i).at(j);
        }
        cout << '\n';
    }

    return 0;
}

