// An example on finding the shortest path by bfs 
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int INF = 0x3f3f3f3f;
constexpr int MAXN = 1000005;

struct Node {
    explicit Node(int position, int steps) : position(position), steps(steps) {}
    int position;
    int steps;
};

bitset<MAXN> vis;
int x;

int bfs(const Node &start) {
    queue<Node> q;
    q.push(start);
    vis[0] = true;
    while (!q.empty()) {
        Node u = q.front();
        q.pop();
        for (int i = 1; i <= 5; ++i) {
            int new_position = u.position + i;
            int new_step = u.steps + 1;
            if (new_position >= 0 && new_position <= x && !vis[new_position]) {
                if (new_position == x) {
                    return new_step;
                }
                q.push(Node(new_position, new_step));
                vis[new_position] = true;
            }
        }
    }
    return INF;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> x;
    cout << bfs(Node(0, 0)) << '\n';

    return 0;
}
