#include <iostream>
#include <string>
#include <bitset>
#include <vector>
#include <numeric>

using namespace std;

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

inline
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

constexpr int MAXN = 105;
constexpr int STEPS = 8;
const int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int m, n;
bitset<MAXN> vis[MAXN];
vector<vector<char> > M;

inline
void dfs(int last_i, int last_j, int i, int j) {
    if (!(last_i == -1 && last_j == -1)) {
        DSU::merge(last_i * n + last_j, i * n + j);
    }
    if (vis[i][j]) {
        return;
    }
    vis[i][j] = true;
    int new_i, new_j;
    for (int step = 0; step < STEPS; ++step) {
        new_i = i + dx[step];
        new_j = j + dy[step];
        if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && M.at(new_i).at(new_j) == '@') {
            dfs(i, j, new_i, new_j);
        }
    }
}


int main() {

    fast_io();
    string s;
    while (true) {
        cin >> m >> n;
        if (m == 0) break;
        for (int i = 0; i < m; ++i) {
            cin >> s;
            M.emplace_back(s.begin(), s.end());
        }
        DSU::init(m * n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (M.at(i).at(j) == '@' && !vis[i][j]) {
                    dfs(-1, -1, i, j);
                }
            }
        }
        bitset<MAXN * MAXN> groups;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (M.at(i).at(j) == '@') {
                    groups[DSU::find(i * n + j)] = true;
                }
            }
        }
        // output
        cout << groups.count() << '\n';
        // reset
        decltype(M)().swap(M);
        for (auto & i : vis) {
            i.reset();
        }
    }

    return 0;
}