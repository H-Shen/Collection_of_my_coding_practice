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

unordered_map<char, int> char2pos;
array<int, 8> stats;
void f(const string &s, int pos) {
    for (const char &ch : s) {
        char2pos[ch] = pos;
    }
}

constexpr int MAXN = 55;
char s[MAXN];

int main() {

    // pre
    f("1QAZ", 0);
    f("2WSX", 1);
    f("3EDC", 2);
    f("45RTFGVB", 3);
    f("67YUHJNM", 4);
    f("8IK,", 5);
    f("9OL.", 6);
    f("0-=P[];'/", 7);

    scanf("%s", s);
    for (int i = 0; s[i] != 0; ++i) {
        ++stats.at(char2pos[s[i]]);
    }
    for (int i = 0; i < 8; ++i) {
        IO::writeln(stats.at(i));
    }

    return 0;
}