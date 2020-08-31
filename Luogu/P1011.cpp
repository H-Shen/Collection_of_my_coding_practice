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

struct Node {
    pii on;     // pii.first = a's coeff, pii.second = y's coeff
    pii off;
    pii total;
};

int a, n, m, x;
vector<Node> stations;

int main() {

    IO::read(a, n, m, x);
    stations.resize(n + 1);

    stations.at(1).on.first = 1;
    stations.at(1).on.second = 0;
    stations.at(1).off.first = 0;
    stations.at(1).off.second = 0;
    stations.at(1).total.first = 1;
    stations.at(1).total.second = 0;

    stations.at(2).on.first = 0;
    stations.at(2).on.second = 1;
    stations.at(2).off.first = 0;
    stations.at(2).off.second = 1;
    stations.at(2).total.first = 1;
    stations.at(2).total.second = 0;

    for (int i = 3; i <= n - 1; ++i) {
        stations.at(i).on.first = stations.at(i - 1).on.first + stations.at(i - 2).on.first;
        stations.at(i).on.second = stations.at(i - 1).on.second + stations.at(i - 2).on.second;
        stations.at(i).off.first = stations.at(i - 1).on.first;
        stations.at(i).off.second = stations.at(i - 1).on.second;
        stations.at(i).total.first = stations.at(i - 1).total.first + stations.at(i).on.first - stations.at(i).off.first;
        stations.at(i).total.second = stations.at(i - 1).total.second + stations.at(i).on.second - stations.at(i).off.second;
    }

    stations.at(n).on.first = 0;
    stations.at(n).on.second = 0;
    stations.at(n).off.first = stations.at(n - 1).total.first;
    stations.at(n).off.second = stations.at(n - 1).total.second;

    int y = (m - a * stations.at(n - 1).total.first) / stations.at(n - 1).total.second;
    IO::writeln(stations.at(x).total.first * a + stations.at(x).total.second * y);
    return 0;
}