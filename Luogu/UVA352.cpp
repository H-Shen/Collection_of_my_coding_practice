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

constexpr int MAXN = 30;
constexpr int STEPS = 8;
const int dx[] = {-1, -1, 0, 0, 1, 1, 1, -1};
const int dy[] = {-1, 0, -1, 1, 0, 1, -1, 1};

int n;
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
        if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n &&
            M.at(new_i).at(new_j) == '1') {
            dfs(i, j, new_i, new_j);
        }
    }
}

int main() {

    fast_io();
    string s;
    for (int kase = 1; cin >> n; ++kase) {
        DSU::init(n * n);
        for (int i = 0; i < n; ++i) {
            cin >> s;
            M.emplace_back(s.begin(), s.end());
        }
        // dfs on '1'
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (M.at(i).at(j) == '1' && !vis[i][j]) {
                    dfs(-1, -1, i, j);
                }
            }
        }
        // check '1'
        bitset<MAXN * MAXN> groups;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (M.at(i).at(j) == '1') {
                    groups[DSU::find(i * n + j)] = true;
                }
            }
        }
        // output
        cout << "Image number " << kase << " contains " << groups.count()
             << " war eagles." << '\n';
        // reset
        for (auto &i : vis) {
            i.reset();
        }
        decltype(M)().swap(M);
    }

    return 0;
}