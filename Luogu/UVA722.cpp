#include <regex>
#include <vector>
#include <string>
#include <numeric>
#include <iostream>

using namespace std;
using ll = long long;

constexpr int STEPS = 4;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};

constexpr int MAXN = 105;
const regex re("\\w+");

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
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        Size[y] += Size[x];
        father[x] = y;
    }
}

inline
vector<int> parse(const string &s) {
    vector<int> result;
    for (sregex_iterator it(s.begin(), s.end(), re), end_it; it != end_it; ++it) {
        result.emplace_back(stoi(it->str()));
    }
    return result;
}

int origin_i, origin_j, r, c;
vector<vector<char> > M;
bitset<MAXN> vis[MAXN];

void dfs(int last_i, int last_j, int i, int j) {
    if (!(last_i == -1 && last_j == -1)) {
        DSU::merge(last_i * c + last_j, i * c + j);
    }
    if (vis[i][j]) {
        return;
    }
    vis[i][j] = true;
    int new_i, new_j;
    for (int step = 0; step < STEPS; ++step) {
        new_i = i + dx[step];
        new_j = j + dy[step];
        if (new_i >= 0 && new_i < r && new_j >= 0 && new_j < c && M.at(new_i).at(new_j) == '0') {
            dfs(i, j, new_i, new_j);
        }
    }
}

auto fast_io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};

int main() {

    fast_io();
    int m;
    string s;
    cin >> m;
    cin.get();
    cin.get();
    bool first_case = true;
    while (m--) {
        getline(cin, s);
        auto p = parse(s);
        origin_i = p.front() - 1;
        origin_j = p.back() - 1;
        decltype(M)().swap(M);
        while (true) {
            if (!getline(cin, s) || s.empty()) break;
            M.emplace_back(s.begin(), s.end());
        }
        if (M.at(origin_i).at(origin_j) == '1') {
            cout << 0 << '\n';
        } else {
            r = static_cast<int>(M.size());
            c = static_cast<int>(M.front().size());
            DSU::init(r * c);
            for (auto &i : vis) {
                i.reset();
            }
            dfs(-1, -1, origin_i, origin_j);
            int counter = 0;
            int group_id = DSU::find(origin_i * c + origin_j);
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    if (DSU::find(i * c + j) == group_id) {
                        ++counter;
                    }
                }
            }
            if (first_case) {
                first_case = false;
            } else {
                cout << '\n';
            }
            cout << counter << '\n';
        }
    }

    return 0;
}