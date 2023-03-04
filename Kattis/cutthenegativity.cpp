// https://open.kattis.com/problems/cutthenegativity
//
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int n, val;

struct Edge {
    int u,v,c;
    Edge(int u, int v, int c) : u(u), v(v), c(c){}
};
vector<Edge> edges;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> val;
            if (val != -1) {
                edges.emplace_back(i,j,val);
            }
        }
    }
    sort(edges.begin(), edges.end(), [&](const Edge&l, const Edge&r){
        if (l.u == r.u) {
            return l.v < r.v;
        }
        return l.u < r.u;
    });
    cout << edges.size() << '\n';
    for (const auto&i : edges) {
        cout << i.u << ' ' << i.v << ' ' << i.c << '\n';
    }

    return 0;
}
