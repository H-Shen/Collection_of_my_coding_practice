#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

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

const int dx[] = {1, -1, 5, -5, 10, -10};
constexpr int STEPS = 6;

unordered_map<int, int, custom_hash> dis;
void bfs(int u, int dest) {
    queue<int> q;
    q.push(u);
    dis[u] = 0;
    int new_u;
    while (!q.empty()) {
        if (dis.find(dest) != dis.end()) {
            return;
        }
        u = q.front();
        q.pop();
        for (int i = 0; i < STEPS; ++i) {
            new_u = u + dx[i];
            if (dis.find(new_u) == dis.end()) {
                dis[new_u] = dis[u] + 1;
            } else {
                dis[new_u] = min(dis[new_u], dis[u] + 1);
            }
            q.push(new_u);
        }
    }
}

int main() {

    int a, b;
    cin >> a >> b;
    bfs(a, b);
    cout << dis[b] << '\n';

    return 0;
}
