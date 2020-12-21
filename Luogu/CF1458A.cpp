#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

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

int main() {

    int n, m;
    IO::read(n, m);
    vector<ll> A(n);
    for (auto &i : A) IO::read(i);
    vector<ll> B(m);
    for (auto &i : B) IO::read(i);
    sort(A.begin(), A.end(), greater<>());
    ll result = 0;
    for(int i = 0; i < n - 1; i++) {
        result = gcd(result, A.at(i) - A.at(i + 1));
    }
    for(int i = 0; i < m; i++) {
        IO::write(gcd(result, A.back() + B.at(i)));
        putchar(' ');
    }

    return 0;
}