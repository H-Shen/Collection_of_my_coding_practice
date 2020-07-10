#include <bits/extc++.h>

using namespace std;
using ll = long long;

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
    inline
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
    }
    inline
    int find(int x) {
        if (x != father[x]) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    inline
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        father[x] = y;
        Size[y] += Size[x];
    }
}

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n;
vector<vector<char> > M;
unordered_map<int, int, custom_hash> groups_with_its_number_of_elements;
unordered_map<int, int, custom_hash> groups_with_its_circumference;

inline
void firstPass() {
    int down, right;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (M.at(i).at(j) == '#') {
                down = i + 1;
                right = j + 1;
                // merge the current pos and the south pos
                if (down < n && M.at(down).at(j) == '#') {
                    DSU::merge(n * i + j, n * down + j);
                }
                // merge the current pos and the east pos
                if (right < n && M.at(i).at(right) == '#') {
                    DSU::merge(n * i + j, n * i + right);
                }
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    M.resize(n, vector<char>(n));
    DSU::init(n * n);
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < n; ++j) {
            M.at(i).at(j) = s.at(j);
        }
    }
    firstPass();
    for (int i = 0; i < n * n; ++i) {
        if (M.at(i / n).at(i % n) == '#') {
            ++groups_with_its_number_of_elements[DSU::find(i)];
        }
    }
    int max_area = 0;
    for (const auto &[k, v] : groups_with_its_number_of_elements) {
        max_area = max(max_area, v);
    }
    for (const auto &[k, v] : groups_with_its_number_of_elements) {
        if (v == max_area) {
            groups_with_its_circumference[k] = 0;
        }
    }
    int counter, pos_i, pos_j, new_pos_i, new_pos_j, group_id;
    for (int i = 0; i < n * n; ++i) {
        group_id = DSU::find(i);
        if (groups_with_its_circumference.find(group_id) != groups_with_its_circumference.end()) {
            counter = 0;
            pos_i = i / n;
            pos_j = i % n;
            // calculate the number of non-empty cells around this cell
            for (int step = 0; step < 4; ++step) {
                new_pos_i = pos_i + dx[step];
                new_pos_j = pos_j + dy[step];
                if (new_pos_i >= 0 && new_pos_i < n && new_pos_j >= 0 &&
                    new_pos_j < n && M.at(new_pos_i).at(new_pos_j) == '#') {
                    ++counter;
                }
            }
            // 4->0, 3->1, 2->2, 1->3, 0->4
            groups_with_its_circumference[group_id] += 4 - counter;
        }
    }
    int min_circumference = numeric_limits<int>::max();
    for (const auto &[k, v] : groups_with_its_circumference) {
        min_circumference = min(min_circumference, v);
    }
    // output
    cout << max_area << ' ' << min_circumference << '\n';

    return 0;
}
