// https://open.kattis.com/problems/terraces
//
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
    bool is_same_group(int x, int y) {
        return find(x) == find(y);
    }
}

unordered_set<int> unset;
vector<vector<bool> > vis;
vector<vector<int> > height;
unordered_map<int, vector<int> > groups;
int c, r, total;

pair<int, int> convert(int pos) {
    pair<int, int> res;
    res.first = pos / c;
    res.second = pos % c;
    return res;
}
int convert(int i, int j) {
    return i*c+j;
}

vector<pair<int, int> > transitions = {
        {0, 1},
        {0, -1},
        {-1, 0},
        {1, 0}
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
        if (new_i >= 0 && new_i < r && new_j >= 0 && new_j < c && height.at(new_i).at(new_j) == height.at(pos.first).at(pos.second)) {
            new_u = convert(new_i, new_j);
            DSU::merge(u, new_u);
            dfs(new_u);
        }
    }
}

int main() {

    scanf("%d %d", &c, &r);
    total = r * c;
    DSU::init(total);
    vis.resize(r, vector<bool>(c, false));
    height.resize(r, vector<int>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            scanf("%d", &height.at(i).at(j));
            unset.insert(convert(i, j));
        }
    }
    while (!unset.empty()) {
        dfs(*unset.begin());
    }
    for (int i = 0; i < total; ++i) {
        groups[DSU::find(i)].emplace_back(i);
    }
    size_t counter = 0;
    int current_height;
    int new_i, new_j;
    pair<int, int> group_id_pos;
    pair<int, int> element_id_pos;
    bool skip_this_group;
    for (const auto &[group_id, element_id_list] : groups) {
        group_id_pos = convert(group_id);
        current_height = height.at(group_id_pos.first).at(group_id_pos.second);
        skip_this_group = false;
        for (const auto &element : element_id_list) {
            element_id_pos = convert(element);
            // Scan all four adjacent cells again, make sure it is lower than all of them
            for (const auto &[i, j] : transitions) {
                new_i = element_id_pos.first + i;
                new_j = element_id_pos.second + j;
                if (! (new_i >= 0 && new_i < r && new_j >= 0 && new_j < c)) {
                    continue;
                }
                // Some adjacent cell is lower than this group
                if (height.at(new_i).at(new_j) < current_height) {
                    skip_this_group = true;
                    break;
                }
            }
            if (skip_this_group) {
                break;
            }
        }
        if (!skip_this_group) {
            counter += element_id_list.size();
        }
    }
    printf("%zd\n", counter);
    return 0;
}
