// https://www.nowcoder.com/practice/9a1c1c764ce04fed8ceff7714e74d3b6
// Compiled in C++14(g++5.4)

#include <bits/stdc++.h>

using namespace std;

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
        if (n) t = -t;
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }
}

int main() {

    int n;
    IO::read(n);
    vector<int> A(n);
    for (auto &i : A) {
        IO::read(i);
    }
    sort(A.begin(), A.end());
    auto uniq = unique(A.begin(), A.end());
    for (auto it = A.begin(); it != uniq; ++it) {
        IO::write(*it);
        putchar(' ');
    }
    puts("");
    return 0;
}