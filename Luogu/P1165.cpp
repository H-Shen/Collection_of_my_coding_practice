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

stack<int> A;
stack<int> A_max;

int main() {

    int n, op, val;
    IO::read(n);
    while (n--) {
        IO::read(op);
        if (op == 0) {
            IO::read(val);
            A.emplace(val);
            if (A_max.empty()) {
                A_max.emplace(val);
            } else {
                A_max.emplace(max(val, A_max.top()));
            }
        } else if (op == 1) {
            if (!A.empty()) {
                A.pop();
                A_max.pop();
            }
        } else {
            if (A.empty()) {
                IO::writeln(0);
            } else {
                IO::writeln(A_max.top());
            }
        }
    }

    return 0;
}
