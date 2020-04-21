#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAXN = 64;

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
void getNumber(int n) {

    if (n == 1) {
        IO::writeln(4);
        return;
    }
    if (n == 2) {
        IO::writeln(7);
        return;
    }

    bitset<MAXN> A(n + 1);
    string s = A.to_string();
    deque<char> temp(s.begin(), s.end());
    while (temp.size() > 1 && temp.front() == '0') {
        temp.pop_front();
    }
    // remove initial 1
    temp.pop_front();
    // add 1 to all remaining digits
    for (auto &i : temp) {
        i += 1;
    }
    for (const char &i : temp) {
        if (i == '2') {
            putchar_unlocked('7');
        } else {
            putchar_unlocked('4');
        }
    }
    putchar_unlocked('\n');
}

int main() {
    int k;
    IO::read(k);
    getNumber(k);
    return 0;
}
