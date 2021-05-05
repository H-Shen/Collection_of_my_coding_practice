namespace DSU {
    vector<int> father, Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n+5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n+5,1);
    }
    int find(int x) {
        if (father[x] != x) {
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
        Size[y] += Size[x];
        father[x] = y;
    }
    bool is_same_group(int x, int y) {
        return find(x) == find(y);
    }
}
class Solution {
public:
    Solution() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        sort(edgeList.begin(), edgeList.end(), [](const auto &l, const auto &r){
            return l[2] < r[2];
        });
        vector<int> queriesId(queries.size());
        iota(queriesId.begin(), queriesId.end(), 0);
        sort(queriesId.begin(), queriesId.end(), [&](const auto &l, const auto &r){
            return queries[l][2] < queries[r][2];
        });
        DSU::init(n);
        int m = (int)queries.size();
        int k = (int)edgeList.size();
        int index = 0;
        vector<bool> result(m);
        for (int i = 0; i < m; ++i) {
            while (true) {
                if (index < k && edgeList[index][2] < queries[queriesId[i]][2]) {
                    DSU::merge(edgeList[index][0], edgeList[index][1]);
                    ++index;
                } else {
                    break;
                }
            }
            result[queriesId[i]] = DSU::is_same_group(queries[queriesId[i]][0], queries[queriesId[i]][1]);
        }
        return result;
    }
};