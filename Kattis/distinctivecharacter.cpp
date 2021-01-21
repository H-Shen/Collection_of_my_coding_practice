// https://open.kattis.com/problems/distinctivecharacter

#include <bits/extc++.h>

using namespace std;
using ll = long long;
using ld = long double;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

constexpr int MAXN = 25;
constexpr int INF = 0x3f3f3f3f;
int n, k;
vector<vector<bitset<MAXN> > > adj;
vector<bitset<MAXN> > sources;
vector<int> dist;

void bfs() {
    queue<bitset<MAXN> > q;
    for (const auto &i : sources) {
        q.push(i);
        dist.at(i.to_ullong()) = 0;
    }
    while (!q.empty()) {
        bitset<MAXN> u = q.front();
        q.pop();
        int u_index = (int)u.to_ullong();
        for (const auto &v : adj.at(u_index)) {
            int v_index = (int)v.to_ullong();
            if (dist.at(v_index) == INF) {
                dist.at(v_index) = dist.at(u_index) + 1;
                q.push(v);
            }
        }
    }
}

int main() {

    fast_io();

    cin >> n >> k;
    string s;
    sources.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < k; ++j) {
            sources.at(i)[j] = s.at(j) - '0';
        }
    }
    // construct the graph
    int total = 1 << k;
    adj.resize(total);
    for (int i = 0; i < total; ++i) {
        bitset<MAXN> temp(i);
        for (int j = 0; j < k; ++j) {
            temp.flip(j);
            adj.at(i).emplace_back(temp);
            temp.flip(j);
        }
    }
    // run bfs from multiple sources
    dist.resize(total, INF);
    bfs();
    int maxVal = *max_element(dist.begin(), dist.end());
    for (int i = 0; i < total; ++i) {
        if (dist.at(i) == maxVal) {
            bitset<MAXN> tempBitset(i);
            for (int j = 0; j < k; ++j) {
                cout << tempBitset[j];
            }
            cout << '\n';
            return 0;
        }
    }

    return 0;
}
