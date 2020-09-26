#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

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

vector<vector<int> > M;

void f(int n, int upper_right_i, int upper_right_j) {
    if (n == 2) {
        M.at(upper_right_i).at(upper_right_j) = 1;
        M.at(upper_right_i + 1).at(upper_right_j) = 1;
        M.at(upper_right_i + 1).at(upper_right_j - 1) = 1;
        return;
    }
    int half = n / 2;
    f(half, upper_right_i, upper_right_j);
    f(half, upper_right_i + half, upper_right_j);
    f(half, upper_right_i + half, upper_right_j - half);
}

int main() {

    int n;
    IO::read(n);
    if (n <= 0) {
        return 0;
    }
    n = 1 << n;
    M.resize(n, vector<int>(n, 0));
    f(n, 0, n - 1);
    for (const auto &i : M) {
        for (int j = 0; j < n - 1; ++j) {
            IO::write(i.at(j));
            putchar_unlocked(' ');
        }
        IO::writeln(i.at(n - 1));
    }

    return 0;
}
