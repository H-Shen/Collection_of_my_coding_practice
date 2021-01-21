// https://open.kattis.com/problems/artwork
//
#include <bits/extc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

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

namespace DSU {
    vector<int> father, Size;
    void init(int n) {
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
    }
    int find(int x) {
        if (father[x] != x) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (Size[x] > Size[y]) swap(x, y);
        Size[y] += Size[x];
        father[x] = y;
    }
}

constexpr int MAXN = 1005;
constexpr int TOTALN = 1000005;
constexpr int STEPS = 4;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
bitset<MAXN> A[MAXN];
bitset<TOTALN> groups;

int main() {

    int n, m, q, r1, c1, r2, c2;
    IO::read(m, n, q);
    DSU::init(n * m);
    vector<vector<pii> > steps;
    for (int i = 0; i < q; ++i) {
        IO::read(c1, r1, c2, r2);
        --r1; --c1; --r2; --c2;
        vector<pii> temp;
        if (r1 == r2 && c1 != c2) {
            for (int j = c1; j <= c2; ++j) {
                if (!A[r1][j]) {
                    temp.emplace_back(r1, j);
                    A[r1][j] = true;
                }
            }
        }
        else {
            for (int j = r1; j <= r2; ++j) {
                if (!A[j][c1]) {
                    temp.emplace_back(j, c1);
                    A[j][c1] = true;
                }
            }
        }
        steps.emplace_back(temp);
    }
    vector<int> cc;
    int new_i, new_j;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!A[i][j]) {
                for (int step = 0; step < STEPS; ++step) {
                    new_i = i + dx[step];
                    new_j = j + dy[step];
                    if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && !A[new_i][new_j]) {
                        DSU::merge(i * m + j, new_i * m + new_j);
                    }
                }
            }
        }
    }
    // count the CCs
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!A[i][j]) {
                groups[DSU::find(i * m + j)] = true;
            }
        }
    }
    int final_cc = groups.count();
    cc.emplace_back(final_cc);
    // reverse the steps
    int length = (int)steps.size();
    for (int i = length - 1; i >= 0; --i) {
        for (const auto &[r, c] : steps.at(i)) {
            // count the CCs around
            unordered_set<int> ccAround;
            int new_r, new_c;
            for (int step = 0; step < STEPS; ++step) {
                new_r = r + dx[step];
                new_c = c + dy[step];
                if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < m && !A[new_r][new_c]) {
                    ccAround.insert(DSU::find(new_r * m + new_c));
                    DSU::merge(r * m + c, new_r * m + new_c);
                }
            }
            final_cc -= ((int)ccAround.size() - 1);
            // restore
            A[r][c] = false;
        }
        cc.emplace_back(final_cc);
    }
    cc.pop_back();
    reverse(cc.begin(), cc.end());
    for (const auto &i : cc) {
        IO::writeln(i);
    }

    return 0;
}
