#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

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

    int k, n, val;
    IO::read(k, n);
    vector<unordered_map<int, int> > A(k);
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            IO::read(val);
            A.at(i)[val] = j;
        }
    }
    int counter = 0;
    bool isBigger;
    bool conform;
    for (int i = 1; i <= n - 1; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            conform = true;
            for (int g = 0; g < k; ++g) {
                if (g == 0) {
                    isBigger = A.at(g)[i] > A.at(g)[j];
                } else if (isBigger && A.at(g)[i] < A.at(g)[j]) {
                    conform = false;
                    break;
                } else if (!isBigger && A.at(g)[i] > A.at(g)[j]) {
                    conform = false;
                    break;
                }
            }
            if (conform) {
                ++counter;
            }
        }
    }
    IO::writeln(counter);

    return 0;
}