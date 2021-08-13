// https://open.kattis.com/problems/martiandna

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

constexpr int INF = 0x3f3f3f3f;
int n,k,r,val,freq,counter;
vector<int> A;
bool flag = false;

bool cmp(unordered_map<int,int> &f, unordered_map<int,int> &s) {
    for (const auto &[i,j] : f) {
        if (s.find(i) == s.end() || s[i] < j) {
            return false;
        }
    }
    return true;
}

int main() {

    IO::read(n,k,r);
    A.resize(n);
    for (auto &i : A) IO::read(i);
    unordered_map<int,int> unmap;
    while (r--) {
        IO::read(val,freq);
        unmap[val] = freq;
        counter += freq;
    }
    int ans = INF;
    deque<int> dq;
    unordered_map<int,int> stats;
    for (const auto &i : A) {
        dq.push_back(i);
        ++stats[i];
        while (!dq.empty() && (unmap.find(dq.front()) == unmap.end() || stats[dq.front()] > unmap[dq.front()])) {
            --stats[dq.front()];
            if (stats[dq.front()] == 0) {
                stats.erase(dq.front());
            }
            dq.pop_front();
        }
        if (!flag && (int)dq.size() >= counter && cmp(unmap,stats)) {
            flag = true;
        }
        if (flag && (int)dq.size() < ans && (int)dq.size() >= counter && unmap.find(i) != unmap.end() && stats[i] >= unmap[i]) {
            ans = (int)dq.size();
        }
    }
    if (ans == INF) {
        puts("impossible");
    } else {
        IO::writeln(ans);
    }
    return 0;
}
