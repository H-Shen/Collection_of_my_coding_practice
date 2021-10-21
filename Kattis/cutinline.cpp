// https://open.kattis.com/problems/cutinline

#include <bits/extc++.h>

using namespace std;
using ll = long long;

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

int n, m;
vector<string> A;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    A.resize(n);
    for (auto &i : A) cin >> i;
    cin >> m;
    string op, a, b;
    while (m--) {
        cin >> op;
        if (op == "cut") {
            cin >> a >> b;
            auto iter = find(A.begin(),A.end(),b);
            A.insert(iter, a);
        } else {
            cin >> a;
            auto iter = find(A.begin(),A.end(),a);
            A.erase(iter);
        }
    }
    for (auto &i : A) cout << i << '\n';
    return 0;
}
