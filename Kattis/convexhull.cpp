// https://open.kattis.com/problems/convexhull

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pt = pair<ll,ll>;

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

ll ccw(pt a, pt b, pt c) {
    return (b.first-a.first)*(c.second-a.second)-(b.second-a.second)*(c.first-a.first);
}

vector<pt> pts;
int n;
void convexHull() {
    vector<pt>  b,t;
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    for (const pt &p : pts) {
        while (b.size() >= 2 && ccw(b[b.size()-2], b[b.size()-1], p) <= 0) {
            b.pop_back();
        }
        b.emplace_back(p);
        while (t.size() >= 2 && ccw(t[t.size()-2], t[t.size()-1], p) >= 0) {
            t.pop_back();
        }
        t.emplace_back(p);
    }
    pts = b;
    for (int i = (int)(t.size()-2); i > 0; --i) {
        pts.emplace_back(t[i]);
    }
}

int main() {

    while (true) {
        IO::read(n);
        if (n == 0) break;
        pts.resize(n);
        for (auto &i : pts) {
            IO::read(i.first,i.second);
        }
        convexHull();
        IO::writeln(pts.size());
        for (const auto &i : pts) {
            IO::write(i.first);
            putchar_unlocked(' ');
            IO::writeln(i.second);
        }
        // reset
        decltype(pts)().swap(pts);
    }
    return 0;
}
