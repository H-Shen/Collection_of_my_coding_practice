#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

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

inline static
ll get_range(const vector<int> &L, const int &obj_pos, const int &d) {
    int obj = L.at(obj_pos);
    int lower = obj - d;
    int lower_pos;
    if (lower < L.front()) {
        lower_pos = 0;
    } else if (lower > L.back()) {
        lower_pos = (int)L.size() - 1;
    } else {
        lower_pos = lower_bound(L.begin(), L.end(), lower) - L.begin();
    }
    ll counter = obj_pos - lower_pos;
    int upper = obj + d;
    int upper_pos;
    if (upper < L.front()) {
        upper_pos = 0;
    } else if (upper > L.back()) {
        upper_pos = (int)L.size() - 1;
    } else {
        upper_pos = (--upper_bound(L.begin(), L.end(), upper)) - L.begin();
    }
    counter += upper_pos - obj_pos;
    return counter;
}

int main() {

    int n, d;
    IO::read(n, d);
    vector<int> A(n);
    for (auto &i : A) IO::read(i);
    sort(A.begin(), A.end());
    ll counter = 0;
    for (int i = 0; i < n; ++i) {
        counter += get_range(A, i, d);
    }
    IO::writeln(counter / 2);

    return 0;
}
