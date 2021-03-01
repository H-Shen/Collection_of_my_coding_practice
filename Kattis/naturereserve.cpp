// https://open.kattis.com/problems/naturereserve

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


namespace MST_Prim {
    vector<vector<pair<int, ll> > > AL;
    vector<bool> taken;
    vector<bool> is_station;
    priority_queue<pair<ll, int> > pq;
    int n;
    void process(int u) {
        taken[u] = true;
        for (auto &[v, w] : AL[u])
            if (!taken[v])
                pq.push({-w, -v});
    }
    ll mst_cost = 0;
    int num_taken = 0;
    void reset() {
        mst_cost = 0;
        num_taken = 0;
        decltype(pq)().swap(pq);
        vector<bool>().swap(is_station);
        vector<bool>().swap(taken);
        decltype(AL)().swap(AL);
        n = 0;
    }
    void prim(const vector<int> &A, ll l) {
        is_station.resize(n, false);
        for (const auto &i : A) is_station.at(i) = true;
        taken.resize(n, false);
        for (const auto &i : A) process(i);
        while (!pq.empty()) {
            auto [w, u] = pq.top();
            pq.pop();
            w = -w; u = -u;
            if (taken[u]) continue;
            mst_cost += w;
            if (!is_station.at(u)) {
                mst_cost += l;
            }
            process(u);
            ++num_taken;
            if (num_taken == n-1) break;
        }
    }
}


int main() {

    int t, n, m, s, u, v;
    ll w, l;
    IO::read(t);
    while (t--) {
        IO::read(n, m, l, s);
        vector<int> stations(s);
        for (auto &i : stations) IO::read(i);
        MST_Prim::n = n + 1;
        MST_Prim::AL.resize(n + 1);
        for (int i = 0; i < m; ++i) {
            IO::read(u, v, w);
            MST_Prim::AL.at(u).emplace_back(v, w);
            MST_Prim::AL.at(v).emplace_back(u, w);
        }
        MST_Prim::prim(stations, l);
        IO::writeln(MST_Prim::mst_cost);
        MST_Prim::reset();
    }

    return 0;
}
