// https://open.kattis.com/problems/flowergarden

#include <bits/stdc++.h>

using namespace std;
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

constexpr int MAXN = 20005;
constexpr double EPS = 1e-7;
bitset<MAXN> isNotPrime;
inline static
void init() {
    isNotPrime[0] = true;
    isNotPrime[1] = true;
    for (int i = 2; i < MAXN; i++) {
        if (!isNotPrime[i]) {
            if (i > MAXN / i) {
                continue;
            }
            for (int j = i * i; j < MAXN; j += i) {
                isNotPrime[j] = true;
            }
        }
    }
}

int sgn(const double &x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

double dist(int x, int y, int a, int b) {
    return sqrt((x-a)*(x-a)+(y-b)*(y-b));
}

int main() {

    init();
    int t, n;
    double d;
    IO::read(t);
    while (t--) {
        IO::read(n, d);
        int answer = 0;
        int cur_x = 0;
        int cur_y = 0;
        double total_dist = 0.0;
        vector<pair<int, int> > flowers(n);
        for (auto &i : flowers) {
            IO::read(i.first, i.second);
        }
        for (int i = 0; i < n; ++i) {
            total_dist += dist(cur_x, cur_y, flowers.at(i).first, flowers.at(i).second);
            if (sgn(total_dist - d) > 0) break;
            cur_x = flowers.at(i).first;
            cur_y = flowers.at(i).second;
            if (!isNotPrime[i + 1]) {
                answer = max(answer, i + 1);
            }
        }
        IO::writeln(answer);
    }

    return 0;
}
