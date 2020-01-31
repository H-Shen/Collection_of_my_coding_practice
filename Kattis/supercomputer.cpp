// https://open.kattis.com/problems/supercomputer
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAX = 1000005;
constexpr int MAX_STR_LEN = 5;
char op[MAX_STR_LEN];

template<int N, int D=1>
class FenwickTree {
    vector<int> tree;
    int isum(int ps) {return tree[ps];}
    template<class... T>
    int isum(int ps, int n, T... tail) {
        int a = 0;
        while (n) {
            a += isum(ps*N + n, tail...);
            n -= (n & -n);
        }
        return a;
    }
    void iupd(int u, int ps) {tree[ps] += u;}
    template<class... T>
    void iupd(int u, int ps, int n, T... tail) {
        while (n < N) {
            iupd(u, ps*N + n, tail...);
            n += (n & -n);
        }
    }
public:
    FenwickTree() : tree(pow(N, D)) {}
    template<class... T>
    int sum(T... v) {return isum(0, v...);}
    template<class... T>
    void upd(int u, T... v) {iupd(u, 0, v...);}
};

int main() {

    FenwickTree<MAX> t;
    unordered_map<int, int> update;
    int n, k, index, l, r;
    scanf("%d %d", &n, &k);
    while (k--) {
        scanf("%s", op);
        if (strcmp(op, "F") == 0) {
            scanf("%d", &index);
            if (update.find(index) == update.end()) {
                update[index] = 1;
                t.upd<int>(1, index);
            } else if (update[index] == 1) {
                update[index] = 0;
                t.upd<int>(-1, index);
            } else {
                update[index] = 1;
                t.upd<int>(1, index);
            }
        } else {
            scanf("%d %d", &l, &r);
            if (l == 1) {
                printf("%d\n", t.sum<int>(r));
            } else {
                printf("%d\n", t.sum<int>(r) - t.sum<int>(l - 1));
            }
        }
    }


    return 0;
}
