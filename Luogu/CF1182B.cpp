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

constexpr int MAXN = 505;
constexpr int STEPS = 4;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int w, h;
vector<vector<char> > M;
bitset<MAXN> vis[MAXN];

void dfs(int last_i, int last_j, int cur_i, int cur_j) {
    if (!(last_i == -1 && last_j == -1)) {
        DSU::merge(last_i * w + last_j, cur_i * w + cur_j);
    }
    vis[cur_i][cur_j] = true;
    int new_i, new_j;
    for (int step = 0; step < STEPS; ++step) {
        new_i = cur_i + dx[step];
        new_j = cur_j + dy[step];
        if (new_i >= 0 && new_i < h && new_j >= 0 && new_j < w &&
            M.at(new_i).at(new_j) == '*' && !vis[new_i][new_j]) {
            dfs(cur_i, cur_j, new_i, new_j);
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

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> h >> w;
    string s;
    for (int i = 0; i < h; ++i) {
        cin >> s;
        M.emplace_back(s.begin(), s.end());
    }
    DSU::init(h * w);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (M.at(i).at(j) == '*' && !vis[i][j]) {
                dfs(-1, -1, i, j);
            }
        }
    }
    unordered_map<int, unordered_set<int, custom_hash>, custom_hash> unmap;
    int temp;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (M.at(i).at(j) == '*') {
                temp = i * w + j;
                unmap[DSU::find(temp)].insert(temp);
            }
        }
    }
    if (unmap.size() != 1) {
        cout << "NO" << '\n';
    } else {
        int centre_counter = 0;
        int centre_i = 0;
        int centre_j = 0;
        int cur_i, cur_j, new_i, new_j;
        bool is_centre;
        for (const auto &pos : unmap.begin()->second) {
            cur_i = pos / w;
            cur_j = pos % w;
            is_centre = true;
            for (int step = 0; step < STEPS; ++step) {
                new_i = cur_i + dx[step];
                new_j = cur_j + dy[step];
                if (unmap.begin()->second.find(new_i * w + new_j) ==
                    unmap.begin()->second.end()) {
                    is_centre = false;
                    break;
                }
            }
            if (is_centre) {
                ++centre_counter;
                centre_i = cur_i;
                centre_j = cur_j;
            }
        }
        if (centre_counter != 1) {
            cout << "NO" << '\n';
        } else {
            // up
            cur_i = centre_i;
            cur_j = centre_j;
            --cur_i;
            while (cur_i >= 0 && cur_i < h && cur_j >= 0 && cur_j < w &&
                   M.at(cur_i).at(cur_j) == '*') {
                unmap.begin()->second.erase(cur_i * w + cur_j);
                --cur_i;
            }
            // down
            cur_i = centre_i;
            cur_j = centre_j;
            ++cur_i;
            while (cur_i >= 0 && cur_i < h && cur_j >= 0 && cur_j < w &&
                   M.at(cur_i).at(cur_j) == '*') {
                unmap.begin()->second.erase(cur_i * w + cur_j);
                ++cur_i;
            }
            // left
            cur_i = centre_i;
            cur_j = centre_j;
            --cur_j;
            while (cur_i >= 0 && cur_i < h && cur_j >= 0 && cur_j < w &&
                   M.at(cur_i).at(cur_j) == '*') {
                unmap.begin()->second.erase(cur_i * w + cur_j);
                --cur_j;
            }
            // right
            cur_i = centre_i;
            cur_j = centre_j;
            ++cur_j;
            while (cur_i >= 0 && cur_i < h && cur_j >= 0 && cur_j < w &&
                   M.at(cur_i).at(cur_j) == '*') {
                unmap.begin()->second.erase(cur_i * w + cur_j);
                ++cur_j;
            }
            // self
            unmap.begin()->second.erase(centre_i * w + centre_j);
            // check
            if (unmap.begin()->second.empty()) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }

    return 0;
}