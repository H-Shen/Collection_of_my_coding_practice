#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar_unlocked(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

namespace DSU {
    vector<int> father;
    vector<int> Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
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
    }
}

constexpr int MAXN = 1005;
constexpr int STEPS = 4;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

bitset<MAXN> vis[MAXN];
vector<vector<char> > M;
unordered_map<int, vector<int>, custom_hash> groups;
int n, m;

void dfs(int last, int i, int j) {
    vis[i][j] = true;
    int pos = i * m + j;
    if (last != -1) {
        DSU::merge(last, pos);
    }
    // iterate 4 directions
    int new_i, new_j;
    for (int step = 0; step < STEPS; ++step) {
        new_i = i + dx[step];
        new_j = j + dy[step];
        if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && !vis[new_i][new_j] && M.at(new_i).at(new_j) == '#') {
            dfs(pos, new_i, new_j);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;
    DSU::init(n * m);
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        M.emplace_back(s.begin(), s.end());
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (M.at(i).at(j) == '#' && !vis[i][j]) {
                dfs(-1, i, j);
            }
        }
    }
    for (int i = 0; i < n * m; ++i) {
        if (M.at(i / m).at(i % m) == '#') {
            groups[DSU::find(i)].emplace_back(i);
        }
    }
    int left, right, up, down, area, counter, pos_i, pos_j;
    int ships_counter = 0;
    for (const auto &[k, v_list] : groups) {
        counter = static_cast<int>(v_list.size());
        left = numeric_limits<int>::max();
        right = numeric_limits<int>::min();
        up = numeric_limits<int>::max();
        down = numeric_limits<int>::min();
        for (const auto &v : v_list) {
            pos_i = v / m;
            up = min(up, pos_i);
            down = max(down, pos_i);
            pos_j = v % m;
            left = min(left, pos_j);
            right = max(right, pos_j);
        }
        area = (right - left + 1) * (down - up + 1);
        if (area != counter) {
            cout << "Bad placement." << '\n';
            return 0;
        }
        ++ships_counter;
    }
    cout << "There are " << ships_counter << " ships." << '\n';
    return 0;
}