// https://open.kattis.com/problems/crosscountry
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace SSSP {
    constexpr ll MAX_NODES = 1005;
    constexpr ll MAX_EDGES = 1005 * 1005;
    constexpr ll INF = 0x3f3f3f3f3f3f;
    struct Edge {
        ll to;
        ll distance;
        ll next;
        bool operator==(const Edge &other) const {
            return to == other.to && distance == other.distance &&
                   next == other.next;
        }
    };
    vector<Edge> E(MAX_EDGES);
    vector<ll> head(MAX_NODES);
    vector<ll> prev(MAX_NODES, -1);
    ll counter;
    vector<ll> dis(MAX_NODES);
    vector<bool> vis(MAX_NODES);
    ll s;

    inline void
    add_edge(ll u, ll v, ll d) {
        ++counter;
        E.at(counter).distance = d;
        E.at(counter).to = v;
        E.at(counter).next = head.at(u);
        head.at(u) = counter;
    }
    struct Node {
        ll distance;
        ll position;

        explicit Node(ll distance, ll pos) : distance(distance), position(pos) {}

        bool operator<(const Node &x) const {
            return (x.distance < distance);
        }
    };
    std::priority_queue<Node> Q;
    inline void dijkstra(bool store_path = false) {
        dis.at(s) = 0;
        Q.push(Node(0, s));
        while (!Q.empty()) {
            Node tmp = Q.top();
            Q.pop();
            ll x = tmp.position;
            // Base case
            if (vis.at(x)) {
                continue;
            }
            vis.at(x) = true;
            for (ll i = head.at(x); i; i = E.at(i).next) {
                ll y = E.at(i).to;
                if (dis.at(y) > dis.at(x) + E.at(i).distance) {
                    dis.at(y) = dis.at(x) + E.at(i).distance;
                    if (store_path) {
                        prev.at(y) = x;
                    }
                    if (!vis.at(y)) {
                        Q.push(Node(dis.at(y), y));
                    }
                }
            }
        }
    }
    inline void reset() {
        fill(dis.begin(), dis.end(), INF);
        vector<bool>().swap(vis);
        vis.resize(MAX_NODES);
        Q = std::priority_queue<Node>();
    }
    vector<ll> get_path(ll t) {
        vector<ll> path;
        for(; t!=-1; t=prev.at(t))
            path.push_back(t);
        reverse(path.begin(),path.end());
        return path;
    }
}

int main() {

    ll n, s, t, w;
    scanf("%lld %lld %lld", &n, &s, &t);
    SSSP::s = s;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            scanf("%lld", &w);
            SSSP::add_edge(i, j, w);
        }
    }
    SSSP::reset();
    SSSP::dijkstra();
    printf("%lld\n", SSSP::dis.at(t));
    return 0;
}
