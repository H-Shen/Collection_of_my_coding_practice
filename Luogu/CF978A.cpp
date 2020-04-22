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
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar('\n');
    }
}

constexpr int MAXN = 1005;
bool vis[MAXN];

int main() {

    int n;
    IO::read(n);
    vector<int> A(n);
    for (auto &i : A) IO::read(i);
    vector<int> output;
    for (int i = n - 1; i >= 0; --i) {
        if (!vis[A.at(i)]) {
            output.emplace_back(A.at(i));
            vis[A.at(i)] = true;
        }
    }
    IO::writeln(output.size());
    bool first_item = true;
    for (auto iter = output.crbegin(); iter != output.crend(); ++iter) {
        if (first_item) {
            first_item = false;
        } else {
            putchar(' ');
        }
        IO::write(*iter);
    }
    putchar('\n');
    return 0;
}