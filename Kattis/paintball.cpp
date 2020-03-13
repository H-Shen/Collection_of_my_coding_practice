// https://open.kattis.com/problems/paintball
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

namespace MCBM {
    const int MAXN = 5005;
    const int MAXM = 10005;
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
}

int main() {

    int n, m;
    scanf("%d %d", &n, &m);
    MCBM::init();
    MCBM::uN = n;
    int u, v;
    while (m--) {
        scanf("%d %d", &u, &v);
        MCBM::addedge(u - 1, v - 1);
        MCBM::addedge(v - 1, u - 1);
    }
    if (MCBM::hungary() == n) {
        for (int i = 0; i < MCBM::uN; ++i) {
            printf("%d\n", MCBM::linker[i] + 1);
        }
    } else {
        printf("Impossible\n");
    }

    return 0;
}
