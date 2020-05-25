#include <bits/extc++.h>

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

int main(int argc, char *argv[]) {

    int n;
    IO::read(n);
    vector<pair<int, int> > A(n);
    for (auto &i : A) {
        IO::read(i.first, i.second);
        i.second += i.first;
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (A.at(i).first == A.at(j).second && A.at(i).second == A.at(j).first) {
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");

    return 0;
}