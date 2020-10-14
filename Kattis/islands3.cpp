// https://open.kattis.com/problems/islands3
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

namespace DSU {
    vector<int> father;
    vector<int> Size;
    void init(int n) {
        father.resize(n + 5);
        Size.resize(n + 5, 1);
        iota(father.begin(), father.end(), 0);
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

constexpr int MAXN = 55;
constexpr int STEPS = 4;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int r, c;
vector<vector<char> > M;
bitset<MAXN> vis[MAXN];

void dfs(int i, int j) {
    if (vis[i][j]) {
        return;
    }
    vis[i][j] = true;
    int new_i, new_j;
    for (int step = 0; step < STEPS; ++step) {
        new_i = i + dx[step];
        new_j = j + dy[step];
        if (new_i >= 0 && new_i < r && new_j >= 0 && new_j < c) {
            if (M[new_i][new_j] == 'L') {
                dfs(new_i, new_j);
            } else if (M[new_i][new_j] == 'C') {
                M[new_i][new_j] = 'L';
                dfs(new_i, new_j);
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c;
    string s;
    for (int i = 0; i < r; ++i) {
        cin >> s;
        M.emplace_back(s.begin(), s.end());
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (M[i][j] == 'L' && !vis[i][j]) {
                dfs(i, j);
            }
        }
    }
    DSU::init(r * c);
    int new_i, new_j;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (M[i][j] == 'L') {
                for (int step = 0; step < STEPS; ++step) {
                    new_i = i + dx[step];
                    new_j = j + dy[step];
                    if (new_i >= 0 && new_i < r && new_j >= 0 && new_j < c && M[new_i][new_j] == 'L') {
                        DSU::merge(i * c + j, new_i * c + new_j);
                    }
                }
            }
        }
    }
    bitset<MAXN * MAXN> counter;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (M[i][j] == 'L') {
                counter[DSU::find(i * c + j)] = true;
            }
        }
    }
    cout << counter.count() << '\n';
    return 0;
}
