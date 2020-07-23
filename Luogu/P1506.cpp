#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 505;
constexpr int STEPS = 4;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int x, y;
vector<vector<char> > A;
bitset<MAXN> vis[MAXN];
void dfs(const int &cur_x, const int &cur_y) {
    vis[cur_x][cur_y] = true;
    int new_x, new_y;
    for (int i = 0; i < STEPS; ++i) {
        new_x = cur_x + dx[i];
        new_y = cur_y + dy[i];
        if (new_x >= 0 && new_x < x && new_y >= 0 && new_y < y && !vis[new_x][new_y]) {
            dfs(new_x, new_y);
        }
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> x >> y;
    string s;
    A.resize(x + 2, vector<char>(y + 2, '0'));
    for (int i = 0; i < x; ++i) {
        cin >> s;
        for (size_t j = 1; j != s.size() + 1; ++j) {
            A.at(i + 1).at(j) = s.at(j - 1);
        }
    }
    x += 2;
    y += 2;
    // fill all '0' outside of '*'
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            if (A.at(i).at(j) == '*') {
                vis[i][j] = true;
            }
        }
    }
    dfs(0, 0);
    int counter = 0;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            if (!vis[i][j]) {
                ++counter;
            }
        }
    }
    cout << counter << '\n';
    return 0;
}