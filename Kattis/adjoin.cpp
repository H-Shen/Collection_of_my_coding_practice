// https://open.kattis.com/problems/adjoin

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

// Obtain the tree diameter by DP
namespace TreeDiameter1 {
    // the longest distance each node can reach
    vector<int> d1;
    // the second longest distance each node can reach
    vector<int> d2;
    vector<vector<int> > adj;
    void init(int n) {
        adj.resize(n);
        d1.resize(n);
        d2.resize(n);
    }
    void dfs(int u, int father_of_u) {
        d1.at(u) = 0;
        d2.at(u) = 0;
        for (const auto &v : adj.at(u)) {
            if (v == father_of_u) continue;
            dfs(v, u);
            int temp = d1.at(v) + 1;
            if (temp > d1.at(u)) {
                d2.at(u) = d1.at(u);
                d1.at(u) = temp;
            } else if (temp > d2.at(u)) {
                d2.at(u) = temp;
            }
        }
    }
}

namespace DSU {
    vector<int> father, Size;
    int number_of_sets;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
        number_of_sets = n;
    }
    int find(int x) {
        if (x != father[x]) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        father[x] = y;
        Size[y] += Size[x];
        --number_of_sets;
    }
    bool is_same_group(int i, int j) {
        return find(i) == find(j);
    }
    int check_set_size(int x) {
        return Size[find(x)];
    }
    int number_of_disjoint_sets() {
        return number_of_sets;
    }
}

int main() {

    int n, m, u, v;
    IO::read(n, m);
    TreeDiameter1::init(n);
    DSU::init(n);
    while (m--) {
        IO::read(u, v);
        TreeDiameter1::adj.at(u).emplace_back(v);
        TreeDiameter1::adj.at(v).emplace_back(u);
        DSU::merge(u, v);
    }
    unordered_map<int, int> groupId2Diameter;
    for (int i = 0; i < n; ++i) {
        int temp = DSU::find(i);
        groupId2Diameter[temp] = 0;
    }
    for (auto &[a, b] : groupId2Diameter) {
        TreeDiameter1::dfs(a, -1);
    }
    for (int i = 0; i < n; ++i) {
        int temp = DSU::find(i);
        groupId2Diameter[temp] = max(groupId2Diameter[temp], TreeDiameter1::d1.at(i) + TreeDiameter1::d2.at(i));
    }

    int maxDiameterOfAllCC = -1;
    vector<int> radius;
    for (const auto &[a, b] : groupId2Diameter) {
        radius.emplace_back((b + 1) / 2);
        maxDiameterOfAllCC = max(maxDiameterOfAllCC, b);
    }
    sort(radius.begin(), radius.end(), greater<>());

    if (groupId2Diameter.size() == 1) {
        IO::writeln(maxDiameterOfAllCC);
    } else if (groupId2Diameter.size() == 2) {
        IO::writeln(max(maxDiameterOfAllCC, radius.at(0) + radius.at(1) + 1));
    } else {
        IO::writeln(max(radius.at(0) + radius.at(1) + 1, max(maxDiameterOfAllCC, radius.at(1) + radius.at(2) + 2)));
    }

    return 0;
}
