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

int n;
vector<int> cols;
vector<int> rows;
vector<vector<int> > A;
vector<pair<int, int> > places;

int main() {

    IO::read(n);
    A.resize(n + 1, vector<int>(n + 1));
    cols.resize(n + 1);
    rows.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            IO::read(A.at(i).at(j));
            if (A.at(i).at(j) == 0) {
                places.emplace_back(make_pair(i, j));
            } else {
                cols.at(j) += A.at(i).at(j);
                rows.at(i) += A.at(i).at(j);
            }
        }
    }
    if (places.empty()) {
        fputs_unlocked("Bad Game!", stdout);
    } else {
        int max_ememy = numeric_limits<int>::min();
        for (const auto &[i, j] : places) {
            max_ememy = max(max_ememy, cols.at(j) + rows.at(i));
        }
        IO::writeln(max_ememy);
    }

    return 0;
}
