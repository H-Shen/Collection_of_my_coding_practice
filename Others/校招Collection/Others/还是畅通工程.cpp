// https://www.nowcoder.com/practice/d6bd75dbb36e410995f8673a6a2e2229

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

int main() {

  int n, m;
  while (~scanf("%d", &n) && n != 0) {
      m = n*(n-1)/2;
      vector<Kruskal::Edge> A(m);
      for (int i = 0; i < m; ++i) {
          scanf("%d %d %d", &A.at(i).u, &A.at(i).v, &A.at(i).w);
      }
      printf("%d\n", Kruskal::init(A, n));
  }
  
  return 0;
}
