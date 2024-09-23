// https://www.nowcoder.com/practice/4878e6c6a24e443aac5211d194cf3913

#include <bits/stdc++.h>

using namespace std;

namespace DSU {
    vector<int> father;
    vector<int> Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
    }
    int find(int x) {
        if (x != father[x]) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        father[x] = y;
        Size[y] += Size[x];
    }
    bool is_same_group(int x, int y) {
        return find(x) == find(y);
    }
}

namespace Kruskal {
    struct Edge {
        int u, v, w;
    };
    bool cmp(const Edge &l, const Edge &r) {
        return (l.w < r.w);
    }
    int init(vector<Edge> A, int number_of_nodes) {
        DSU::init(number_of_nodes);
        sort(A.begin(), A.end(), cmp);
        int min_cost = 0;
        for (const auto &i : A) {
            if (!DSU::is_same_group(i.u, i.v)) {
                DSU::merge(i.u, i.v);
                min_cost += i.w;
            }
        }
        return min_cost;
 
    }
}

constexpr int MAXN = 1005;

int main() {

  int n, m, x, y;
  while (~scanf("%d", &n) && n != 0) {
      DSU::init(MAXN);
      scanf("%d", &m);
      while (m--) {
          scanf("%d %d", &x, &y);
          DSU::merge(x, y);
      }  
      unordered_set<int> groups;
      for (int i = 1; i <= n; ++i) {
          groups.insert(DSU::find(i));
      }
      printf("%d\n", static_cast<int>(groups.size() - 1));
  }
  return 0;
}
