// https://open.kattis.com/problems/pathcrossings

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MAXN = 105;
constexpr int MAXDIST = 1000000;

namespace IO {
    template<typename T>
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
    bool can_read(T &t, Args &... args) {
        return can_read(t) && can_read(args...);
    }
    template<typename T>
    void read(T &t) {
        int n = 0;
        int c = getchar_unlocked();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }
    template<typename T, typename... Args>
    void read(T &t, Args &... args) {
        read(t);
        read(args...);
    }
    template<typename T>
    void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }
    template<typename T>
    void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

int P,N,p,x,y,t;

struct Node {
    int id, x, y;
    Node() = default;
    Node(int id, int x, int y) : id(id), x(x), y(y) {}
};

vector<tuple<int,int,int,int>> temp;
vector<vector<Node>> vec;
vector<int> times;
bitset<MAXN> vis[MAXN];

int main(){
    IO::read(P,N);
    temp.resize(N);
    times.resize(N);
    for (int i = 0; i < N; ++i) {
        IO::read(p,x,y,t);
        times[i] = t;
        get<0>(temp[i]) = p;
        get<1>(temp[i]) = x;
        get<2>(temp[i]) = y;
        get<3>(temp[i]) = t;
    }
    sort(times.begin(), times.end());
    times.erase(unique(times.begin(), times.end()), times.end());
    vec.resize(times.size());
    for (int i = 0; i < N; ++i) {
        p = get<0>(temp[i]);
        x = get<1>(temp[i]);
        y = get<2>(temp[i]);
        t = get<3>(temp[i]);
        vec[(int)(lower_bound(times.begin(),times.end(),t) - times.begin())].emplace_back(p,x,y);
    }
    int lowerbound, upperbound;
    int len = (int)vec.size();
    for (int index = 0; index < len; ++index) {
        lowerbound = max(times[index]-10, 0);
        upperbound = times[index]+10;
        for (int currentTime = lowerbound; currentTime <= upperbound; ++currentTime) {
            if (currentTime != times[index]) {
                if (binary_search(times.begin(),times.end(),currentTime)) {
                    auto&v = vec[(int)(lower_bound(times.begin(),times.end(),currentTime) - times.begin())];
                    for (const auto &i : v) {
                        for (const auto &j : vec[index]) {
                            if ((i.x-j.x)*(i.x-j.x)+(i.y-j.y)*(i.y-j.y) <= MAXDIST) {
                                vis[i.id][j.id] = true;
                                vis[j.id][i.id] = true;
                            }
                        }
                    }
                }
            }
            else {
                int length = (int)vec[index].size();
                if (length > 1) {
                    for (int i = 0; i < length-1; ++i) {
                        for (int j = i+1; j < length; ++j) {
                            if ((vec[index][i].x-vec[index][j].x)*(vec[index][i].x-vec[index][j].x)+(vec[index][i].y-vec[index][j].y)*(vec[index][i].y-vec[index][j].y) <= MAXDIST) {
                                vis[vec[index][i].id][vec[index][j].id] = true;
                                vis[vec[index][j].id][vec[index][i].id] = true;
                            }
                        }
                    }
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= P-1; ++i) {
        for (int j = i+1; j <= P; ++j) {
            if (vis[i][j]) {
                ++cnt;
            }
        }
    }
    IO::writeln(cnt);
    for (int i = 1; i <= P-1; ++i) {
        for (int j = i+1; j <= P; ++j) {
            if (vis[i][j]) {
                IO::write(i);
                putchar_unlocked(' ');
                IO::writeln(j);
            }
        }
    }

    return 0;
}
