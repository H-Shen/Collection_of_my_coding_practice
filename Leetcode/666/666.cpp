class Solution {
public:
    vector<int> weight, father, dp;
    int solve(int u) {
        if (dp[u] != -1) {
            return dp[u];
        }
        dp[u] = weight[u];
        if (father[u] != -1) {
            dp[u] += solve(father[u]);
        }
        return dp[u];
    }
    int pathSum(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int>().swap(weight);
        weight.resize(n);
        unordered_map<int,int> unmap;
        for (int i = 0; i < n; ++i) {
            unmap[nums[i] / 10] = i;
            weight[i] = nums[i] % 10;
        }
        int temp, level, pos;
        vector<int>().swap(father);
        father.resize(n);
        for (const auto &[k,v] : unmap) {
            temp = k;
            pos = temp % 10;
            temp /= 10;
            level = temp;
            if (level == 1) {
                father[v] = -1;
            }
            else if (pos & 1) {
                father[v] = unmap[(level-1)*10+((pos+1)>>1)];
            }
            else {
                father[v] = unmap[(level-1)*10+(pos>>1)];
            }
        }
        vector<vector<int>> AL(n);
        for (int i = 1; i < n; ++i) {
            AL[father[i]].emplace_back(i);
        }
        vector<int>().swap(dp);
        dp.resize(n,-1);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (AL[i].empty()) {
                ans += solve(i);
            }
        }
        return ans;
    }
};