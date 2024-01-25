#include <iostream>
#include <unordered_set>
#include <string>
#include <array>
#include <queue>

using namespace std;

constexpr int STEPS = 4;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};

struct myHashFunction {
    size_t operator() (const array<array<int, 3>, 3> &v) const {
        size_t h = 0;
        for (const auto &i : v) {
            for (const auto &j : i) {
                h ^= hash<int>{}(j) + 0x9e3779b9 + (h << 6) + (h >> 2);
            }
        }
        return h;
    }
};

array<array<int, 3>, 3> target_status = {1,2,3,8,0,4,7,6,5};

int bfs(array<array<int, 3>, 3> initial_status) {
    queue<pair<array<array<int, 3>, 3>, int>> q;
    q.emplace(initial_status, 0);
    unordered_set<array<array<int, 3>, 3>, myHashFunction> memo;
    memo.insert(initial_status);
    pair<array<array<int, 3>, 3>, int> p;
    int i, j, new_i, new_j;
    bool found;
    while (!q.empty()) {
        p = q.front();
        q.pop();
        if (p.first == target_status) {
            return p.second;
        }
        found = false;
        for (int pos_i = 0; pos_i < 3; ++pos_i) {
            for (int pos_j = 0; pos_j < 3; ++pos_j) {
                if (p.first[pos_i][pos_j] == 0) {
                    i = pos_i;
                    j = pos_j;
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        for (int step = 0; step < STEPS; ++step) {
            new_i = i + dx[step];
            new_j = j + dy[step];
            if (new_i >= 0 && new_i < 3 && new_j >= 0 && new_j < 3) {
                swap(p.first[new_i][new_j], p.first[i][j]);
                if (memo.count(p.first) == 0) {
                    memo.insert(p.first);
                    q.emplace(p.first, p.second+1);
                }
                // restore
                swap(p.first[new_i][new_j], p.first[i][j]);
            }
        }
    }
    return -1;
}

int main() {
    string s;
    cin >> s;
    array<array<int, 3>, 3> initial_status;
    for (int i = 0, k = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            initial_status[i][j] = s[k] - '0';
            ++k;
        }
    }
    cout << bfs(initial_status) << '\n';
    return 0;
}
