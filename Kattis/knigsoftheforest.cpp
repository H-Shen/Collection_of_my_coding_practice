// https://open.kattis.com/problems/knigsoftheforest

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace IO {
    template<typename T>
    inline
    bool can_read(T &t) {
        int n = 0;
        int ch = getchar_unlocked();
        while (!isdigit(ch)) {
            if (ch == EOF) return false;
            n |= ch == '-';
            ch = getchar_unlocked();
        }
        t = 0;
        while (isdigit(ch)) {
            t = t * 10 + ch - 48;
            ch = getchar_unlocked();
        }
        if (n) t = -t;
        return true;
    }

    template<typename T, typename... Args>
    inline
    bool can_read(T &t, Args &... args) {
        return can_read(t) && can_read(args...);
    }

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

int poolSize, n, y, p;

int main() {
    IO::read(poolSize, n, y, p);
    vector<pair<int,int>> vec(n + poolSize - 2);
    int length = (int)vec.size();
    for (auto &[i,j] : vec) {
        IO::read(i, j);
    }
    sort(vec.begin(),vec.end(),[](const auto &l, const auto &r){
        return l.first < r.first;
    });
    int i;
    int counter = 0;
    for (i = 0; i < length && vec[i].first <= y; ++i) {
        if (vec[i].second < p) ++counter;
    }
    for (; i < length; ++i) {
        if (vec[i].second < p) {
            ++counter;
            if (counter == poolSize-1) {
                break;
            }
        }
    }
    if (counter < poolSize-1) {
        puts("unknown");
    }
    else {
        if (i == length) {
            IO::writeln(y);
        } else {
            IO::writeln(vec[i].first);
        }
    }
    return 0;
}
