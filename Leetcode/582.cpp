class Solution {
public:
    vector<int> ans;
    unordered_map<int, unordered_set<int> > AL;
    void dfs(int u, int father_of_u) {
        ans.emplace_back(u);
        for (auto &v : AL[u]) {
            if (v != father_of_u) {
                dfs(v, u);
            }
        }
    }
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        AL.clear();
        int n = (int)pid.size();
        int root = -1;
        for (int i = 0; i < n; ++i) {
            if (ppid[i] == 0) {
                root = pid[i];
                AL[root];
                continue;
            }
            AL[ppid[i]].insert(pid[i]);
        }
        int father_of_kill = -1;
        for (int i = 0; i < n; ++i) {
            if (pid[i] == kill) {
                father_of_kill = ppid[i];
                break;
            }
        }
        vector<int>().swap(ans);
        // dfs
        dfs(kill, father_of_kill);
        return ans;
    }
};