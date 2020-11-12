#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

namespace IO {
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar_unlocked();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }

    template<typename T, typename... Args>
    inline
    void read(T &t, Args &... args) {
        read(t);
        read(args...);
    }

    template<typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

namespace MDST {
    constexpr int INF = 0x3f3f3f3f;
    struct Edge {
        explicit Edge(int u, int v, int w) : u(u), v(v), w(w) {}
        Edge() = default;
        int u, v, w;
    };
    vector<Edge> edges;
    vector<int> pre;
    vector<int> id;
    vector<int> visit;
    vector<int> in;

    void reset() {
        vector<Edge>().swap(edges);
        vector<int>().swap(pre);
        vector<int>().swap(id);
        vector<int>().swap(visit);
        vector<int>().swap(in);
    }

    // return the sum of MDST, or -INF if there is no MDST
    int Edmonds(int root, int number_of_nodes) {
        int number_of_edges = (int)edges.size();
        pre.resize(number_of_nodes + 5);
        id.resize(number_of_nodes + 5);
        visit.resize(number_of_nodes + 5);
        in.resize(number_of_nodes + 5);

        int result = 0;
        int u, v, tn;
        while (true) {
            for (int i = 0; i < number_of_nodes; ++i) {
                in.at(i) = INF;
            }
            for (int i = 0; i < number_of_edges; ++i) {
                if (edges.at(i).u != edges.at(i).v &&
                    edges.at(i).w < in.at(edges.at(i).v)) {
                    pre.at(edges.at(i).v) = edges.at(i).u;
                    in.at(edges.at(i).v) = edges.at(i).w;
                }
            }
            for (int i = 0; i < number_of_nodes; ++i) {
                if (i != root && in.at(i) == INF) {
                    return -INF;    // No MDST exists
                }
            }
            tn = 0;
            fill(id.begin(), id.end(), -1);
            fill(visit.begin(), visit.end(), -1);
            in.at(root) = 0;
            for (int i = 0; i < number_of_nodes; ++i) {
                result += in.at(i);
                v = i;
                while (visit.at(v) != i && id.at(v) == -1 && v != root) {
                    visit.at(v) = i;
                    v = pre.at(v);
                }
                if (v != root && id.at(v) == -1) {
                    for (u = pre.at(v); u != v; u = pre.at(u)) {
                        id.at(u) = tn;
                    }
                    id.at(v) = tn;
                    ++tn;
                }
            }
            if (tn == 0) {
                break;  // No cycles found
            }
            for (int i = 0; i < number_of_nodes; ++i) {
                if (id.at(i) == -1) {
                    id.at(i) = tn;
                    ++tn;
                }
            }
            for (int i = 0; i < number_of_edges; ) {
                v = edges.at(i).v;
                edges.at(i).u = id.at(edges.at(i).u);
                edges.at(i).v = id.at(edges.at(i).v);
                if (edges.at(i).u != edges.at(i).v) {
                    edges.at(i).w -= in.at(v);
                    ++i;
                } else {
                    swap(edges.at(i), edges.at(--number_of_edges));
                }
            }
            number_of_nodes = tn;
            root = id.at(root);
        }
        return result;
    }

}

vector<vector<int> > G;
int m, n;

int main() {

    int t;
    IO::read(t);
    for (int kase = 1; kase <= t; ++kase) {
        IO::read(n, m);
        G.resize(n + 5, vector<int>(n + 5));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                G.at(i).at(j) = MDST::INF;
            }
        }
        int u, v, w;
        for (int i = 0; i < m; ++i) {
            IO::read(u, v, w);
            // Ignore self-loop
            if (u != v) {
                // Only keep the minimal weight
                G.at(u).at(v) = min(G.at(u).at(v), w);
            }
        }
        // add edges
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (G.at(i).at(j) < MDST::INF) {
                    MDST::edges.emplace_back(MDST::Edge(i, j, G.at(i).at(j)));
                }
            }
        }
        // start finding the MDST
        int root = 0;
        int result = MDST::Edmonds(root, n);
        printf("Case #%d: ", kase);
        if (result == -MDST::INF) {
            printf("Possums!\n");
        } else {
            printf("%d\n", result);
        }
        // reset
        vector<vector<int> >().swap(G);
        MDST::reset();
    }


    return 0;
}