#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

constexpr int MAXN = 2005;
constexpr int STEPS = 4;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int r, c, original_i, original_j, left_max, right_max;
vector<vector<char> > M;
bitset<MAXN> vis[MAXN];

struct Node {
    explicit Node(int i, int j, int leftUsed, int rightUsed) : i(i), j(j),
                                                      left_used(leftUsed),
                                                      right_used(rightUsed) {}

    int i, j;
    int left_used;
    int right_used;
};

void dequeBfs(Node u) {
    deque<Node> dq;
    dq.push_back(u);
    vis[u.i][u.j] = true;
    int new_i, new_j;
    while (!dq.empty()) {
        u = dq.front();
        dq.pop_front();
        for (int step = 0; step < STEPS; ++step) {
            new_i = u.i + dx[step];
            new_j = u.j + dy[step];
            if (new_i >= 0 && new_i < r && new_j >= 0 && new_j < c && M.at(new_i).at(new_j) != '*' && !vis[new_i][new_j]) {
                // Move up/down
                if (new_j == u.j) {
                    dq.push_front(Node(new_i, new_j, u.left_used, u.right_used));
                    vis[new_i][new_j] = true;
                }
                // Move left
                else if (new_j < u.j) {
                    if (u.left_used == left_max) {
                        continue;
                    } else {
                        dq.emplace_back(new_i, new_j, u.left_used + 1, u.right_used);
                        vis[new_i][new_j] = true;
                    }
                }
                // Move right
                else {
                    if (u.right_used == right_max) {
                        continue;
                    } else {
                        dq.emplace_back(new_i, new_j, u.left_used, u.right_used + 1);
                        vis[new_i][new_j] = true;
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> r >> c >> original_i >> original_j >> left_max >> right_max;
    --original_i;
    --original_j;
    string s;
    for (int i = 0; i < r; ++i) {
        cin >> s;
        M.emplace_back(s.begin(), s.end());
    }
    dequeBfs(Node(original_i, original_j, 0, 0));
    int counter = 0;
    for (auto &i : vis) {
        counter += (int)i.count();
    }
    cout << counter << '\n';
    return 0;
}