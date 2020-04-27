#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

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

inline static
int convert(bool get_min, int a, int b) {
    string a_str = to_string(a);
    string b_str = to_string(b);
    if (get_min) {
        for (auto &ch : a_str) {
            if (ch == '6') {
                ch = '5';
            }
        }
        for (auto &ch : b_str) {
            if (ch == '6') {
                ch = '5';
            }
        }
    } else {
        for (auto &ch : a_str) {
            if (ch == '5') {
                ch = '6';
            }
        }
        for (auto &ch : b_str) {
            if (ch == '5') {
                ch = '6';
            }
        }
    }
    return stoi(a_str) + stoi(b_str);
}

int main() {
    int a, b;
    IO::read(a, b);
    IO::write(convert(true, a, b));
    putchar_unlocked(' ');
    IO::writeln(convert(false, a, b));
    return 0;
}