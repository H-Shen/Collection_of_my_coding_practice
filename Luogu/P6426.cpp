#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAXN = 3;

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
    
    vector<int> A(MAXN);
    for (auto &&i : A) {
        IO::read(i);
    }
    
    int cnt = 0;
    int diff0 = 0;
    int diff1 = 0;
    while (true) {
        diff0 = A[1] - A[0];
        diff1 = A[2] - A[1];
        if (diff1 == 1 && diff0 == 1) {
            break;
        }

        if (diff1 >= diff0) {
            A[0] = A[1] + 1;
            swap(A[0], A[1]);
        } else {
            A[2] = A[1] - 1;
            swap(A[2], A[1]);
        }
        ++cnt;
    }
    IO::writeln(cnt);
    return 0;
}
