// https://open.kattis.com/problems/bumped
//
#include <bits/extc++.h>

using namespace std;
using ll = long long;

namespace SSSP {
    constexpr ll MAX_NODES = 50005;
    constexpr ll MAX_EDGES = 400050;
    constexpr ll INF = 0x3f3f3f3f3f;    // 0x3f3f3f3f is not enough here!
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
    priority_queue<Node> Q;
    inline void dijkstra() {
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
}


int main() {

    ll n, m, f, s, t, u, v, w;
    scanf("%lld %lld %lld %lld %lld", &n, &m, &f, &s, &t);
    while (m--) {
        scanf("%lld %lld %lld", &u, &v, &w);
        ++u;
        ++v;
        SSSP::add_edge(u, v, w);
        SSSP::add_edge(v, u, w);
    }

    auto E_copy = SSSP::E;
    auto head_copy = SSSP::head;
    auto counter_copy = SSSP::counter;
    ll min_cost = numeric_limits<ll>::max();
    // Case 1: No flights available
    SSSP::reset();
    SSSP::s = s + 1;
    SSSP::dijkstra();
    min_cost = min(min_cost, SSSP::dis.at(t + 1));

    // Case 2:
    while (f--) {
        SSSP::reset();
        scanf("%lld %lld", &u, &v); // free cost of the flight
        ++u;
        ++v;
        SSSP::add_edge(u, v, 0);
        SSSP::s = s + 1;
        SSSP::dijkstra();
        min_cost = min(min_cost, SSSP::dis.at(t + 1));
        SSSP::E = E_copy;
        SSSP::head = head_copy;
        SSSP::counter = counter_copy;
    }
    printf("%lld\n", min_cost);
    return 0;
}
