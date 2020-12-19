#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

namespace DSU {
    vector<int> father, Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5, 0);
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

constexpr int STEPS = 4;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<vector<char> > A;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        A.emplace_back(s.begin(), s.end());
    }
    DSU::init(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int new_i, new_j;
            if (A.at(i).at(j) == '*') {
                for (int step = 0; step < STEPS; ++step) {
                    new_i = i + dx[step];
                    new_j = j + dy[step];
                    if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m &&
                        A.at(new_i).at(new_j) == '*') {
                        DSU::merge(i * m + j, new_i * m + new_j);
                    }
                }
            }
        }
    }
    constexpr int MAXN = 10005;
    bitset<MAXN> vis;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (A.at(i).at(j) == '*') {
                vis[DSU::find(i * m + j)] = true;
            }
        }
    }
    cout << vis.count() << '\n';
    return 0;
}

