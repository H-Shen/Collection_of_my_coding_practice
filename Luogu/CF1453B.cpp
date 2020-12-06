#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

namespace IO {
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
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
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar('\n');
    }
}

ll solve(const vector<ll> &A) {
    int n = (int)A.size();
    ll maximalMoves = 0;
    for (int i = 1; i < n; ++i) {
        maximalMoves += abs(A.at(i) - A.at(i - 1));
    }

    ll temp = -1;
    for (int i = 1; i < n - 1; ++i) {
        temp = max(temp, abs(A.at(i) - A.at(i - 1)) + abs(A.at(i + 1) - A.at(i)) - abs(A.at(i + 1) - A.at(i - 1)));
    }
    ll decreasedMoves = max(
            abs(A.at(1) - A.at(0)), max(
            temp,
            abs(A.at(n - 1) - A.at(n - 2))
    ));
    return maximalMoves - decreasedMoves;
}

int main() {

    int t, n;
    IO::read(t);
    while (t--) {
        IO::read(n);
        vector<ll> A(n);
        for (auto &i : A) IO::read(i);
        IO::writeln(solve(A));
    }

    return 0;
}