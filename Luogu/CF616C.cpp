#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

constexpr int MAXN = 1005;
constexpr int MOD = 10;
constexpr int STEPS = 4;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

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

int r, c;
vector<vector<char> > M;
vector<vector<char> > output;
bitset<MAXN> vis[MAXN];

int convert(int i, int j) {
    return i * c + j;
}

void dfs(int last_i, int last_j, int cur_i, int cur_j) {
    if (!(last_i == -1 && last_j == -1)) {
        DSU::merge(convert(last_i, last_j), convert(cur_i, cur_j));
    }
    if (vis[cur_i][cur_j]) {
        return;
    }
    vis[cur_i][cur_j] = true;
    int new_i, new_j;
    for (int step = 0; step < STEPS; ++step) {
        new_i = cur_i + dx[step];
        new_j = cur_j + dy[step];
        if (new_i >= 0 && new_i < r && new_j >= 0 && new_j < c && M.at(new_i).at(new_j) != '*') {
            dfs(cur_i, cur_j, new_i, new_j);
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
    DSU::init(r * c);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (M.at(i).at(j) == '.' && !vis[i][j]) {
                dfs(-1, -1, i, j);
            }
        }
    }
    output = M;
    int new_i, new_j, counter;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (M.at(i).at(j) == '*') {
                counter = 0;
                unordered_set<int, custom_hash> unmap;
                for (int step = 0; step < STEPS; ++step) {
                    new_i = i + dx[step];
                    new_j = j + dy[step];
                    if (new_i >= 0 && new_i < r && new_j >= 0 && new_j < c && M.at(new_i).at(new_j) == '.') {
                        unmap.insert(DSU::find(convert(new_i, new_j)));
                    }
                }
                for (const auto &k : unmap) {
                    counter += DSU::Size[k];
                }
                counter += 1;   // add self
                counter %= MOD;
                output.at(i).at(j) = '0' + counter;
            }
        }
    }
    // output
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << output.at(i).at(j);
        }
        cout << '\n';
    }

    return 0;
}