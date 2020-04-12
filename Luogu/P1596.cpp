#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

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

unordered_set<int> unset;
vector<vector<bool> > vis;
vector<vector<char> > height;
unordered_set<int> groups;
int c, r, total;

pair<int, int> convert(int pos) {
    pair<int, int> res;
    res.first = pos / c;
    res.second = pos % c;
    return res;
}

int convert(int i, int j) {
    return i * c + j;
}

vector<pair<int, int> > transitions = {
        {0,  1},
        {0,  -1},
        {-1, 0},
        {1,  0},
        {-1, 1},
        {-1, -1},
        {1, -1},
        {1, 1}
};

void dfs(int u) {
    pair<int, int> pos = convert(u);
    if (vis.at(pos.first).at(pos.second)) {
        return;
    }
    vis.at(pos.first).at(pos.second) = true;
    unset.erase(u);
    int new_i, new_j, new_u;
    for (const auto &[i, j] : transitions) {
        new_i = i + pos.first;
        new_j = j + pos.second;
        if (new_i >= 0 && new_i < r && new_j >= 0 && new_j < c &&
            height.at(new_i).at(new_j) == 'W') {
            new_u = convert(new_i, new_j);
            DSU::merge(u, new_u);
            dfs(new_u);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> r >> c;
    total = r * c;
    DSU::init(total);
    vis.resize(r, vector<bool>(c, false));
    string s;
    for (int i = 0; i < r; ++i) {
        cin >> s;
        height.emplace_back(s.begin(), s.end());
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (height.at(i).at(j) == 'W') {
                unset.insert(convert(i, j));
            }
        }
    }
    while (!unset.empty()) {
        dfs(*unset.begin());
    }
    for (int i = 0; i < total; ++i) {
        auto pos = convert(i);
        if (height.at(pos.first).at(pos.second) == 'W') {
            groups.insert(DSU::find(i));
        }
    }
    cout << groups.size() << '\n';

    return 0;
}