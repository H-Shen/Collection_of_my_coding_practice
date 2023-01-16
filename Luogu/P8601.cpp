#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 12;
constexpr int STEPS = 4;

int n,m;
vector<vector<int>> A;
int s;
int minStep;
bitset<MAXN> vis[MAXN];

const int dx[] = {0,-1,1,0};
const int dy[] = {-1,0,0,1};


void dfs(int i, int j, int step, int sum) {
    if (step >= minStep) {
        return;
    }
    if (sum > s) {
        return;
    }
    if (sum == s) {
        minStep = min(minStep, step);
        return;
    }
    int new_i, new_j;
    for (int k = 0; k < STEPS; ++k) {
        new_i = i + dx[k];
        new_j = j + dy[k];
        if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && !vis[new_i][new_j]) {
            vis[new_i][new_j] = true;
            dfs(new_i,new_j,step+1,sum+A[new_i][new_j]);
            vis[new_i][new_j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> m >> n;
    A.resize(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> A[i][j];
            s += A[i][j];
        }
    }
    if (s & 1) {
        cout << 0 << '\n';
        return 0;
    }
    s >>= 1;
    if (A[0][0] > s) {
        cout << 0 << '\n';
        return 0;
    }
    minStep = numeric_limits<int>::max();
    vis[0][0] = true;
    dfs(0, 0, 1, A[0][0]);
    cout << minStep << '\n';
    return 0;
}