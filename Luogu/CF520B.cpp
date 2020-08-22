#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
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

constexpr int MAX = 10005;

int n, m;
gp_hash_table<int, int, custom_hash> dis;
void bfs() {
    queue<int> q;
    q.push(n);
    dis[n] = 0;
    int cur, new_cur;
    while (!q.empty() && dis.find(m) == dis.end()) {
        cur = q.front();
        q.pop();
        new_cur = cur * 2;
        if (new_cur >= 0 && new_cur <= MAX && dis.find(new_cur) == dis.end()) {
            q.push(new_cur);
            dis[new_cur] = dis[cur] + 1;
        }
        new_cur = cur - 1;
        if (new_cur >= 0 && new_cur <= MAX && dis.find(new_cur) == dis.end()) {
            q.push(new_cur);
            dis[new_cur] = dis[cur] + 1;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    bfs();
    cout << dis[m] << '\n';

    return 0;
}
