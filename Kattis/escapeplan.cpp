// https://open.kattis.com/problems/escapeplan
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr double SPEED = 10.0;
constexpr double EPS = 1e-6;
inline static
int sgn(const double &x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

// For the bipartite graph in 5 seconds
namespace MCBM {
    const int MAXN = 305;
    const int MAXM = 50005;
    struct Edge{
        int to,next;
    } edge[MAXM];
    int head[MAXN];
    int tot;
    void init() {
        tot = 0;
        memset(head, -1, sizeof(head));
    }
    void addedge(int u, int v) {
        edge[tot].to = v;
        edge[tot].next = head[u];
        head[u] = tot++;
    }
    int linker[MAXN];
    bool used[MAXN];
    int uN;
    bool dfs(int u) {
        for(int i = head[u]; i != -1 ;i = edge[i].next){
            int v = edge[i].to;
            if(!used[v]) {
                used[v] = true;
                if(linker[v] == -1 || dfs(linker[v])){
                    linker[v] = u;
                    return true;
                }
            }
        }
        return false;
    }
    int hungary(){
        int res = 0;
        memset(linker,-1,sizeof(linker));
        for(int u = 0; u < uN;u++){
            memset(used,false,sizeof(used));
            if(dfs(u))res++;
        }
        return res;
    }
    void reset() {
        memset(edge, 0, sizeof(Edge) * MAXM);
        memset(head, 0, sizeof(int) * MAXN);
        memset(used, false, sizeof(bool) * MAXN);
        memset(linker, 0, sizeof(int) * MAXN);
    }
}
// For the bipartite graph in 10 seconds
namespace MCBM_copy_1 {
    const int MAXN = 305;
    const int MAXM = 50005;
    struct Edge{
        int to,next;
    } edge[MAXM];
    int head[MAXN];
    int tot;
    void init() {
        tot = 0;
        memset(head, -1, sizeof(head));
    }
    void addedge(int u, int v) {
        edge[tot].to = v;
        edge[tot].next = head[u];
        head[u] = tot++;
    }
    int linker[MAXN];
    bool used[MAXN];
    int uN;
    bool dfs(int u) {
        for(int i = head[u]; i != -1 ;i = edge[i].next){
            int v = edge[i].to;
            if(!used[v]) {
                used[v] = true;
                if(linker[v] == -1 || dfs(linker[v])){
                    linker[v] = u;
                    return true;
                }
            }
        }
        return false;
    }
    int hungary(){
        int res = 0;
        memset(linker,-1,sizeof(linker));
        for(int u = 0; u < uN;u++){
            memset(used,false,sizeof(used));
            if(dfs(u))res++;
        }
        return res;
    }
    void reset() {
        memset(edge, 0, sizeof(Edge) * MAXM);
        memset(head, 0, sizeof(int) * MAXN);
        memset(used, false, sizeof(bool) * MAXN);
        memset(linker, 0, sizeof(int) * MAXN);
    }
}
// For the bipartite graph in 20 seconds
namespace MCBM_copy_2 {
    const int MAXN = 305;
    const int MAXM = 50005;
    struct Edge{
        int to,next;
    } edge[MAXM];
    int head[MAXN];
    int tot;
    void init() {
        tot = 0;
        memset(head, -1, sizeof(head));
    }
    void addedge(int u, int v) {
        edge[tot].to = v;
        edge[tot].next = head[u];
        head[u] = tot++;
    }
    int linker[MAXN];
    bool used[MAXN];
    int uN;
    bool dfs(int u) {
        for(int i = head[u]; i != -1 ;i = edge[i].next){
            int v = edge[i].to;
            if(!used[v]) {
                used[v] = true;
                if(linker[v] == -1 || dfs(linker[v])){
                    linker[v] = u;
                    return true;
                }
            }
        }
        return false;
    }
    int hungary(){
        int res = 0;
        memset(linker,-1,sizeof(linker));
        for(int u = 0; u < uN;u++){
            memset(used,false,sizeof(used));
            if(dfs(u))res++;
        }
        return res;
    }
    void reset() {
        memset(edge, 0, sizeof(Edge) * MAXM);
        memset(head, 0, sizeof(int) * MAXN);
        memset(used, false, sizeof(bool) * MAXN);
        memset(linker, 0, sizeof(int) * MAXN);
    }
}

inline static
double dist(const pair<double, double> &l, const pair<double, double> &r) {
    return sqrt( (l.first-r.first)*(l.first-r.first)+(l.second-r.second)*(l.second-r.second) );
}

int main() {

    int m, n;
    int kase = 1;
    while (true) {
        scanf("%d", &m);
        if (m == 0) {
            break;
        }
        vector<pair<double, double> > Robots(m);
        for (auto &i : Robots) {
            scanf("%lf %lf", &i.first, &i.second);
        }
        scanf("%d", &n);
        vector<pair<double, double> > Holes(n);
        for (auto &i : Holes) {
            scanf("%lf %lf", &i.first, &i.second);
        }
        printf("Scenario %d\n", kase);
        ++kase;
        // in 5 seconds
        MCBM::uN = m;
        MCBM::init();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ( sgn(dist(Robots.at(i), Holes.at(j)) / SPEED - 5.0) <= 0 ) {
                    MCBM::addedge(i, j);
                }
            }
        }
        // output
        printf("In 5 seconds %d robot(s) can escape\n", MCBM::hungary());
        MCBM::reset();

        // in 10 seconds
        MCBM_copy_1::uN = m;
        MCBM_copy_1::init();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ( sgn(dist(Robots.at(i), Holes.at(j)) / SPEED - 10.0) <= 0 ) {
                    MCBM_copy_1::addedge(i, j);
                }
            }
        }
        // output
        printf("In 10 seconds %d robot(s) can escape\n", MCBM_copy_1::hungary());
        MCBM_copy_1::reset();

        // in 20 seconds
        MCBM_copy_2::uN = m;
        MCBM_copy_2::init();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ( sgn(dist(Robots.at(i), Holes.at(j)) / SPEED - 20.0) <= 0 ) {
                    MCBM_copy_2::addedge(i, j);
                }
            }
        }
        // output
        printf("In 20 seconds %d robot(s) can escape\n", MCBM_copy_2::hungary());
        MCBM_copy_2::reset();
        printf("\n");
    }

    return 0;
}
