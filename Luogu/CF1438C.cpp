#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar('\n');
    }
}

int t, n, m;
vector<vector<int> > a, b;

int main() {

    IO::read(t);
    while (t--) {
        IO::read(n, m);
        decltype(a)().swap(a);
        decltype(b)().swap(b);
        a.resize(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                IO::read(a.at(i).at(j));
            }
        }
        b = a;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i + j) % 2 == 1 && b.at(i).at(j) % 2 == 1) {
                    ++b.at(i).at(j);    // even
                }
                else if ((i + j) % 2 == 0 && b.at(i).at(j) % 2 == 0) {
                    ++b.at(i).at(j);    // odd
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                IO::write(b.at(i).at(j));
                putchar(' ');
            }
            putchar('\n');
        }
    }

    return 0;
}