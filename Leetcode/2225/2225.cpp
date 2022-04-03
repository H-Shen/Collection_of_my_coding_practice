constexpr int MAXN = 1e5+5;
constexpr int INF = 0x3f3f3f3f;
int inDeg[MAXN];

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        memset(inDeg, 0x3f, sizeof inDeg);
        int u,v;
        for (auto&i : matches) {
            u = i[0];
            v = i[1];
            if (inDeg[u] == INF) inDeg[u] = 0;
            if (inDeg[v] == INF) {
                inDeg[v] = 1;
            } else {
                ++inDeg[v];
            }
        }
        vector<int> v1,v2;
        for (int i = 0; i < MAXN; ++i) {
            if (inDeg[i] == 0) v1.emplace_back(i);
            if (inDeg[i] == 1) v2.emplace_back(i);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        vector<vector<int>> ans;
        ans.emplace_back(v1);
        ans.emplace_back(v2);
        return ans;
    }
};