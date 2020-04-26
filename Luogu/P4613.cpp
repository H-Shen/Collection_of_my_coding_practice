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

int main() {

    int n;
    IO::read(n);
    vector<int> wand(n);
    for (auto &i : wand) IO::read(i);
    vector<int> wand_box(n);
    for (auto &i : wand_box) IO::read(i);
    sort(wand.begin(), wand.end(), greater<>());
    sort(wand_box.begin(), wand_box.end(), greater<>());
    for (int i = 0; i < n; ++i) {
        if (wand_box.at(i) < wand.at(i)) {
            puts("NE");
            return 0;
        }
    }
    puts("DA");

    return 0;
}