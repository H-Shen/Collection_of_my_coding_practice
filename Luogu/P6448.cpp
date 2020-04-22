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

constexpr int MAXN = 5;
array<int, MAXN> A_final;
array<int, MAXN> A;

void output() {
    printf("%d", A[0]);
    for (int i = 1; i < MAXN; ++i) {
        printf(" %d", A[i]);
    }
    printf("\n");
}

int main() {

    iota(A_final.begin(), A_final.end(), 1);
    for (int i = 0; i < MAXN; ++i) {
        IO::read(A.at(i));
    }
    while (A != A_final) {
        if (A[0] > A[1]) {
            swap(A[0], A[1]);
            output();
        }
        if (A[1] > A[2]) {
            swap(A[1], A[2]);
            output();
        }
        if (A[2] > A[3]) {
            swap(A[2], A[3]);
            output();
        }
        if (A[3] > A[4]) {
            swap(A[3], A[4]);
            output();
        }
    }

    return 0;
}
