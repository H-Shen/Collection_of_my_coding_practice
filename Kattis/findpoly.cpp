// https://open.kattis.com/problems/findpoly

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

constexpr int MAXN = 10005;
constexpr int INF = 0x3f3f3f3f;
int degree[MAXN];
unordered_map<int, vector<int> > adj;


int convert(int i, int j) {
    return i * 100 + j;
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

void f(const string &s) {
    static const regex r("[0-9]+");
    istringstream iss(s);
    string p;
    int i0, j0, i1, j1, u, v;
    while (getline(iss, p, ';')) {
        for (sregex_iterator it(p.begin(), p.end(), r), end_it; it != end_it; ) {
            i0 = stoi(it->str());
            ++it;
            j0 = stoi(it->str());
            ++it;
            i1 = stoi(it->str());
            ++it;
            j1 = stoi(it->str());
            ++it;
            u = convert(i0, j0);
            v = convert(i1, j1);
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
            DSU::merge(u, v);
            ++degree[u];
            ++degree[v];
        }
    }
}

bool eulerian(const vector<int> &vList) {
    return all_of(vList.begin(), vList.end(), [](const auto &v) {
        return degree[v] % 2 == 0;
    });
}

bool f(const vector<int> &vList) {
    int edges = 0;
    for (const auto &v : vList) {
        edges += (int)adj[v].size();
    }
    return edges / 2 == (int)vList.size();
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    char ch;
    while (cin >> ch) {
        if (ch != ' ') {
            s.push_back(ch);
        }
    }
    DSU::init(MAXN);
    f(s);
    unordered_map<int, vector<int> > groups;
    for (const auto &[u, vList] : adj) {
        groups[DSU::find(u)].emplace_back(u);
    }
    int polygon_counter = 0;
    for (const auto &[k, v] : groups) {
        if (eulerian(v) && f(v)) {  // image a polygon as a circle
            ++polygon_counter;
        }
    }
    cout << groups.size() << ' ' << polygon_counter << '\n';
    return 0;
}
