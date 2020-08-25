// https://open.kattis.com/problems/tornbygge
//
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

int main() {

    int n;
    IO::read(n);
    int counter = 0;
    deque<int> temp;
    int val;
    while (n--) {
        IO::read(val);
        if (temp.empty()) {
            temp.emplace_back(val);
        } else if (val <= temp.front()) {
            temp.push_front(val);
        } else {
            ++counter;
            temp.clear();
            temp.emplace_back(val);
        }
    }
    if (!temp.empty()) {
        ++counter;
    }
    IO::writeln(counter);

    return 0;
}
