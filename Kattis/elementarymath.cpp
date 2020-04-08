// https://open.kattis.com/problems/elementarymath
//
#include <bits/extc++.h>

using namespace std;
using ll = long long;

namespace MCBM {
    const int MAXN = 10005;
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
    int linker_rev[MAXN];
    bool used[MAXN];
    int uN; // left side
    bool dfs(int u) {
        for(int i = head[u]; i != -1 ;i = edge[i].next){
            int v = edge[i].to;
            if(!used[v]) {
                used[v] = true;
                if(linker[v] == -1 || dfs(linker[v])){
                    linker_rev[u] = v;
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

vector<pair<ll, ll> > Left;
unordered_map<ll, int> Right;
vector<ll> Right_rev;
int right_counter = 0;

int main() {

    int n;
    scanf("%d", &n);
    MCBM::init();
    ll a, b, c;
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &a, &b);
        Left.emplace_back(make_pair(a, b));
        // +
        c = a + b;
        if (Right.find(c) == Right.end()) {
            Right[c] = right_counter;
            Right_rev.emplace_back(c);
            ++right_counter;
        }
        MCBM::addedge(i, Right[c]);
        // -
        c = a - b;
        if (Right.find(c) == Right.end()) {
            Right[c] = right_counter;
            Right_rev.emplace_back(c);
            ++right_counter;
        }
        MCBM::addedge(i, Right[c]);
        // *
        c = a * b;
        if (Right.find(c) == Right.end()) {
            Right[c] = right_counter;
            Right_rev.emplace_back(c);
            ++right_counter;
        }
        MCBM::addedge(i, Right[c]);
    }
    MCBM::uN = n;
    if (MCBM::hungary() != n) {
        printf("impossible\n");
    } else {
        for (int i = 0; i < n; ++i) {
            a = Left.at(i).first;
            b = Left.at(i).second;
            c = Right_rev[MCBM::linker_rev[i]];
            if (a + b == c) {
                printf("%lld + %lld = %lld\n", a, b, c);
            } else if (a - b == c) {
                printf("%lld - %lld = %lld\n", a, b, c);
            } else {
                printf("%lld * %lld = %lld\n", a, b, c);
            }
        }
    }

    return 0;
}
