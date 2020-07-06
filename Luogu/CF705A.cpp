#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

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

inline static
string multiply(const string &s, int n) {
    string result;
    for (int i = 0; i < n; ++i) {
        result += s;
    }
    return result;
}

int main() {

    int n;
    string s;
    IO::read(n);
    if (n == 1) {
        s = "I hate it";
    } else if (n == 2) {
        s = "I hate that I love it";
    } else {
        bool first_item = true;
        for (int i = 0; i < n; ++i) {
            if (first_item) {
                first_item = false;
            } else {
                s.push_back(' ');
            }
            if (i % 2 == 0) {
                if (i == n - 1) {
                    s += "I hate it";
                } else {
                    s += "I hate that";
                }
            } else {
                if (i == n - 1) {
                    s += "I love it";
                } else {
                    s += "I love that";
                }
            }
        }
    }
    fputs(s.c_str(), stdout);
    putchar('\n');

    return 0;
}
