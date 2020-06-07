// https://open.kattis.com/problems/starwarsmovies
//
// __gnu_cxx::rope example
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
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

rope<int> Rope;

int main() {

    int n, q, x;
    IO::read(n);
    int counter = 1;
    while (n--) {
        IO::read(q, x);
        --x;
        auto iter = Rope.mutable_begin();
        if (q == 1) {
            Rope.insert(iter + x, counter);
            ++counter;
        } else {
            IO::writeln(*(iter + x));
        }
    }

    return 0;
}
