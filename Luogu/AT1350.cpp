#include <vector>
#include <iostream>
#include <numeric>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

namespace DSU {
    vector<int> father;
    vector<int> Size;
    void init(int n) {
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
        if (x == y) return;
        if (Size[x] > Size[y]) swap(x, y);
        Size[y] += Size[x];
        father[x] = y;
    }
}

constexpr int MAXN = 505;
constexpr int STEPS = 4;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {-1, 1, 0, 0};

vector<vector<char> > M;
int n, m, original_i, original_j, dest_i, dest_j;

void find_cc() {
    int new_i, new_j;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (M.at(i).at(j) != '#') {
                for (int step = 0; step < STEPS; ++step) {
                    new_i = i + dx[step];
                    new_j = j + dy[step];
                    if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && M.at(new_i).at(new_j) != '#') {
                        DSU::merge(i * m + j, new_i * m + new_j);
                    }
                }
            }
        }
    }
}

int main() {

    cin >> n >> m;
    DSU::init(n * m);
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        M.emplace_back(s.begin(), s.end());
        for (int j = 0; j < m; ++j) {
            if (s.at(j) == 'g') {
                dest_i = i;
                dest_j = j;
            }
            else if (s.at(j) == 's') {
                original_i = i;
                original_j = j;
            }
        }
    }
    find_cc();
    if (DSU::find(original_i * m + original_j) == DSU::find(dest_i * m + dest_j)) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }



    return 0;
}