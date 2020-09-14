#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using pii = pair<int, int>;

constexpr int MAXN = 25;
constexpr int STEPS = 8;
constexpr int HALF_STEPS = STEPS / 2;
constexpr array<int, STEPS> dx = {0, 0, 1, -1, -1, -1, 1, 1};
constexpr array<int, STEPS> dy = {1, -1, 0, 0, 1, -1, 1, -1};

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
        if (father[x] != x) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        father[x] = y;
        Size[y] += Size[x];
    }
}

auto fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};

int n, m, original_i, original_j;
vector<vector<char> > M;
bitset<MAXN> vis[MAXN];

void dfs(int last_i, int last_j, int cur_i, int cur_j) {
    if (!(last_i == -1 && last_j == -1)) {
        DSU::merge(last_i * m + last_j, cur_i * m + cur_j);
    }
    if (vis[cur_i][cur_j]) {
        return;
    }
    vis[cur_i][cur_j] = true;
    int new_i, new_j;
    for (int step = 0; step < STEPS; ++step) {
        new_i = cur_i + dx[step];
        new_j = cur_j + dy[step];
        if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && M.at(new_i).at(new_j) == 'X') {
            dfs(cur_i, cur_j, new_i, new_j);
        }
    }
}

int main() {

    fast_io();
    cin >> n >> m >> original_i >> original_j;
    DSU::init(n * m);
    --original_i;
    --original_j;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        M.emplace_back(s.begin(), s.end());
    }
    dfs(-1, -1, original_i, original_j);
    int group_id = DSU::find(original_i * m + original_j);
    vector<pii> group;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (DSU::find(i * m + j) == group_id) {
                group.emplace_back(i, j);
            }
        }
    }
    int circumference = 0;
    int new_i, new_j;
    for (const auto &[i, j] : group) {
        for (int step = 0; step < HALF_STEPS; ++step) {
            new_i = i + dx[step];
            new_j = j + dy[step];
            if (new_i < 0 || new_i >= n || new_j < 0 || new_j >= m || M.at(new_i).at(new_j) == '.') {
                ++circumference;
            }
        }
    }
    cout << circumference << '\n';

    return 0;
}
