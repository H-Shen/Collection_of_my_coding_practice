#include <bits/stdc++.h>

using namespace std;
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

inline
bool is_ambiguous(const vector<int> &A, int n) {
    vector<int> A_(n + 1);
    for (int i = 1; i <= n; ++i) {
        A_.at(A.at(i)) = i;
    }
    return A_ == A;
}

int main() {

    int n;
    while (true) {
        IO::read(n);
        if (n == 0) break;
        vector<int> A(n + 1);
        for (int i = 1; i <= n; ++i) {
            IO::read(A.at(i));
        }
        if (!is_ambiguous(A, n)) {
            printf("not ");
        }
        printf("ambiguous\n");
    }

    return 0;
}