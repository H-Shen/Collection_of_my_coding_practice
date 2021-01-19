// https://open.kattis.com/problems/emptyingbaltic
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 505;
constexpr int STEPS = 8;

const int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int dy[] = {0, 0, -1, 1, 1, -1, -1, 1};

vector<vector<ll> > A;
vector<vector<ll> > dist;
bitset<MAXN> vis[MAXN];

struct Node {
    int i, j;
    ll val;
    Node() = default;
    Node(int i, int j, ll val) : i(i), j(j), val(val) {}
    bool operator < (const Node &other) const {
        return val > other.val;
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int h, w;
    cin >> h >> w;
    dist.resize(h, vector<ll>(w));
    A.resize(h, vector<ll>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> A[i][j];
        }
    }
    int r, c;
    cin >> r >> c;
    --r;
    --c;
    std::priority_queue<Node> pq;
    pq.push(Node(r, c, A[r][c]));
    vis[r][c] = true;
    dist[r][c] = A[r][c];
    Node cur;
    int new_i, new_j;
    while (!pq.empty()) {
        cur = pq.top();
        pq.pop();
        for (int step = 0; step < STEPS; ++step) {
            new_i = cur.i + dx[step];
            new_j = cur.j + dy[step];
            if (new_i >= 0 && new_i < h && new_j >= 0 && new_j < w && !vis[new_i][new_j] && A[new_i][new_j] < 0) {
                vis[new_i][new_j] = true;
                dist[new_i][new_j] = max(A[new_i][new_j], cur.val);
                pq.push(Node(new_i, new_j, dist[new_i][new_j]));
            }
        }
    }
    ll total = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (dist[i][j] < 0) {
                total += -dist[i][j];
            }
        }
    }
    cout << total << '\n';

    return 0;
}
