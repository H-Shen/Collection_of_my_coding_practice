// https://open.kattis.com/problems/mazemakers

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 55;
constexpr int STEPS = 4;

// anti-clockwise
const int dx[] = {0,1,0,-1};
const int dy[] = {-1,0,1,0};
const int last[] = {2,3,0,1};

int n,m,src_i,src_j,dest_i,dest_j;
vector<vector<int>> A;
string s;
bitset<MAXN> vis[MAXN];

bool visAll() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!vis[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        A.resize(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            cin >> s;
            for (int j = 0; j < m; ++j) {
                if (s[j] >= '0' && s[j] <= '9') A[i][j] = s[j] - '0';
                else A[i][j] = s[j] - 'A' + 10;
            }
        }
        src_i = -1;
        dest_i = -1;
        for (int i = 0; i < n; ++i) {
            if ((A[i][0] >> 0 & 1) == 0) {
                if (src_i == -1) {
                    src_i = i;
                    src_j = 0;
                }
                else {
                    dest_i = i;
                    dest_j = 0;
                    break;
                }
            }
            if ((A[i][m-1] >> 2 & 1) == 0) {
                if (src_i == -1) {
                    src_i = i;
                    src_j = m-1;
                }
                else {
                    dest_i = i;
                    dest_j = m-1;
                    break;
                }
            }
        }
        for (int j = 0; j < m; ++j) {
            if ((A[0][j] >> 3 & 1) == 0) {
                if (src_i == -1) {
                    src_i = 0;
                    src_j = j;
                }
                else {
                    dest_i = 0;
                    dest_j = j;
                    break;
                }
            }
            if ((A[n-1][j] >> 1 & 1) == 0) {
                if (src_i == -1) {
                    src_i = n-1;
                    src_j = j;
                }
                else {
                    dest_i = n-1;
                    dest_j = j;
                    break;
                }
            }
        }
        // bfs
        struct Node {
            int i,j,last;
            Node() = default;
            Node(int i, int j, int last) : i(i), j(j), last(last) {}
        };
        queue<Node> q;
        q.push({src_i,src_j,-1});
        vis[src_i][src_j] = true;
        int new_i,new_j;
        bool hasMultiplePaths = false;
        while (!q.empty()) {
            Node node = q.front();
            q.pop();
            for (int step = 0; step < STEPS; ++step) {
                // ignore the path coming from the last position
                if (step == node.last) {
                    continue;
                }
                if ((A[node.i][node.j] >> step & 1) == 1) {
                    continue;
                }
                new_i = node.i+dx[step];
                new_j = node.j+dy[step];
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m) {
                    if (vis[new_i][new_j]) {
                        hasMultiplePaths = true;
                    } else {
                        vis[new_i][new_j] = true;
                        q.push(Node(new_i,new_j,last[step]));
                    }
                }
            }
        }
        if (!vis[src_i][src_j] || !vis[dest_i][dest_j]) {
            cout << "NO SOLUTION" << '\n';
        }
        else if (!visAll()) {
            cout << "UNREACHABLE CELL" << '\n';
        }
        else if (hasMultiplePaths) {
            cout << "MULTIPLE PATHS" << '\n';
        }
        else {
            cout << "MAZE OK" << '\n';
        }
        vector<vector<int>>().swap(A);
        for (auto &i : vis) i.reset();
    }
    return 0;
}
