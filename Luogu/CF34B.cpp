#include <bits/extc++.h>

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

int main() {

    int n, m;
    IO::read(n, m);
    vector<int> A(n);
    for (auto &i : A) IO::read(i);
    sort(A.begin(), A.end());
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        if (A.at(i) < 0) {
            sum += abs(A.at(i));
        } else {
            break;
        }
    }
    IO::writeln(sum);

    return 0;
}
