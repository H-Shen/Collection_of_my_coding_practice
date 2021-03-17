// https://open.kattis.com/problems/fromatob

#include <bits/stdc++.h>

using namespace std;
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
        static const uint64_t FIXED_RANDOM =
                chrono::steady_clock::now().
                time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    size_t operator()(pair<uint64_t, uint64_t> x) const {
        static const uint64_t FIXED_RANDOM =
                chrono::steady_clock::now().
                time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM) ^
               (splitmix64(x.second + FIXED_RANDOM) >> 1);
    }
};

ll a, b;
unordered_map<ll, int, custom_hash> dist;
void bfs() {
    queue<ll> q;
    q.push(a);
    dist[a] = 0;
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        if (u == b) break;
        if (u > b) {
            if (u % 2 == 0) {
                ll new_u = u / 2;
                if (dist.find(new_u) == dist.end()) {
                    dist[new_u] = dist[u] + 1;
                    q.push(new_u);
                }
            }
            else {
                ll new_u = (u + 1) / 2;
                if (dist.find(new_u) == dist.end()) {
                    dist[new_u] = dist[u] + 2;
                    q.push(new_u);
                }
            }
        }
        else {
            dist[b] = dist[u] + (b - u);
            break;
        }
    }
}

int main() {

    cin >> a >> b;
    bfs();
    cout << dist[b] << '\n';


    return 0;
}
