#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <sstream>
#include <chrono>
#include <bitset>

using namespace std;
using pii = pair<int, int>;

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

inline static
vector<string> splitByChar(string s, const char &delim) {
    vector<string> res;
    istringstream f(s);
    while (getline(f, s, delim)) {
        res.emplace_back(s);
    }
    return res;
}

constexpr int MAXN = 105;
constexpr int STEPS = 8;
const int dx[] = {-1, -1, 0, 0, 1, 1, 1, -1};
const int dy[] = {-1, 0, -1, 1, 0, 1, -1, 1};
int r, c;
vector<string> M;
bitset<MAXN> vis[MAXN];

inline
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
        if (new_i >= 0 && new_i < r && new_j >= 0 && new_j < c &&
            M.at(new_i).at(new_j) == 'W') {
            dfs(i, j, new_i, new_j);
        }
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

int main() {
    fast_io();
    int kase;
    cin >> kase;
    cin.get();
    cin.get();
    string s;
    bool first_case = true;
    while (kase--) {
        if (first_case) {
            first_case = false;
        } else {
            cout << '\n';
        }
        vector<pii> queries;
        while (getline(cin, s)) {
            if (s.empty()) {
                break;
            } else if (isalpha(s.front())) {
                M.emplace_back(s);
            } else {
                auto p = splitByChar(s, ' ');
                queries.emplace_back(make_pair(stoi(p.front()), stoi(p.back())));
            }
        }
        r = static_cast<int>(M.size());
        c = static_cast<int>(M.front().size());
        DSU::init(r * c);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (M.at(i).at(j) == 'W' && !vis[i][j]) {
                    dfs(-1, -1, i, j);
                }
            }
        }
        // stats
        unordered_map<int, int, custom_hash> groups;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (M.at(i).at(j) == 'W') {
                    ++groups[DSU::find(i * c + j)];
                }
            }
        }
        // query
        int pos_i, pos_j;
        for (const auto &i : queries) {
            pos_i = i.first - 1;
            pos_j = i.second - 1;
            if (pos_i >= 0 && pos_i < r && pos_j >= 0 && pos_j < c && M.at(pos_i).at(pos_j) == 'W') {
                cout << groups[DSU::find(pos_i * c + pos_j)] << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
        // reset
        decltype(M)().swap(M);
        for (auto &i : vis) {
            i.reset();
        }
    }

    return 0;
}