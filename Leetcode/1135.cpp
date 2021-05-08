namespace DSU {
    vector<int> father, Size;
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
    bool is_same_group(int i, int j) {
        return find(i) == find(j);
    }
}

class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        constexpr int MAXN = 10005;
        bitset<MAXN> exist;
        DSU::init(N);
        for (const auto &i : connections) {
            exist[i[0]] = true;
            exist[i[1]] = true;
            DSU::merge(i[0],i[1]);
        }
        unordered_set<int> groups;
        for (int i = 1; i <= N; ++i) {
            groups.insert(DSU::find(i));
        }
        if (groups.size() != 1) {
            return -1;
        }
        // Kruskal
        struct Edge {
            int u, v, w;
            explicit Edge() = default;
        };
        int m = (int)connections.size();
        vector<Edge> edgeList(m);
        for (int i = 0; i < m; ++i) {
            edgeList[i].u = connections[i][0];
            edgeList[i].v = connections[i][1];
            edgeList[i].w = connections[i][2];
        }
        sort(edgeList.begin(), edgeList.end(), [](const auto &l, const auto &r){
            return l.w < r.w;
        });
        int sum = 0;
        DSU::init(N);
        for (int i = 0; i < m; ++i) {
            if (!DSU::is_same_group(edgeList[i].u, edgeList[i].v)) {
                DSU::merge(edgeList[i].u, edgeList[i].v);
                sum += edgeList[i].w;
            }
        }
        return sum;
    }
};