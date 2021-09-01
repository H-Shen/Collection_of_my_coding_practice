constexpr int MAXN = 1e5+5;

class Solution {
public:
    int maxCycleLength;
    bitset<MAXN> vis;
    void dfs(vector<int>&nums, int cycleLength, int index) {
        if (!vis[nums[index]]) {
            vis[nums[index]] = true;
            dfs(nums, cycleLength+1, nums[index]);
        }
        else {
            maxCycleLength = max(maxCycleLength, cycleLength);
        }
    }
    int arrayNesting(vector<int>& nums) {
        maxCycleLength = 0;
        vis.reset();
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                vis[i] = true;
                dfs(nums, 1, i);
            }
        }
        return maxCycleLength;
    }
};