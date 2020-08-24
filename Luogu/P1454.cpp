#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 105;
constexpr int STEPS = 13;
const int dx[] = {0, -2, 2, 0, 1, 1, -1, -1, 0, 1, 0, -1, 0};
const int dy[] = {2, 0, 0, -2, 1, -1, 1, -1, 1, 0, -1, 0, 0};

inline
void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }


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
        Size[y] += Size[x];
        father[x] = y;
    }
    bool is_same_group(int x, int y) {
        return find(x) == find(y);
    }
}

vector<vector<char> > M;
bitset<MAXN> vis[MAXN];
int n, m;

void dfs(int last_i, int last_j, int i, int j) {
    if (!(last_i == -1 && last_j == -1)) {
        int last = last_i * m + last_j;
        int cur = i * m + j;
        DSU::merge(last, cur);
    }
    if (vis[i][j]) {
        return;
    }
    vis[i][j] = true;
    int new_i;
    int new_j;
    for (int step = 0; step < STEPS; ++step) {
        new_i = i + dx[step];
        new_j = j + dy[step];
        if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && M.at(new_i).at(new_j) == '#') {
            dfs(i, j, new_i, new_j);
        }
    }
}

int main() {

    fast_io();
    string s;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        M.emplace_back(s.begin(), s.end());
    }
    DSU::init(m * n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (M.at(i).at(j) == '#' && !vis[i][j]) {
                dfs(-1, -1, i, j);
            }
        }
    }
    unordered_set<int> groups;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (M.at(i).at(j) == '#') {
                groups.insert(DSU::find(i * m + j));
            }
        }
    }
    cout << groups.size() << '\n';

    return 0;
}
