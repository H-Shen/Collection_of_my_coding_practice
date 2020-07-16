// https://open.kattis.com/problems/height
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 20;

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

array<int, MAXN> A;
int insertion_sort() {
    int counter = 0;
    for (int i = 1; i < MAXN; i++) {
        int temp = A.at(i);
        int j = i - 1;
        while (j >= 0 && A.at(j) > temp) {
            A.at(j + 1) = A.at(j);
            ++counter;
            --j;
        }
        A.at(j + 1) = temp;
    }
    return counter;
}

int main(int argc, char *argv[]) {

    int t, kase;
    IO::read(t);
    while (t--) {
        IO::read(kase);
        for (int i = 0; i < MAXN; ++i) {
            IO::read(A.at(i));
        }
        IO::write(kase);
        putchar_unlocked(' ');
        IO::writeln(insertion_sort());
    }
    return 0;
}
