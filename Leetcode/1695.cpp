class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        constexpr int MAXN = 1e4+5;
        int maxSum = 0;
        int curSum = 0;
        bitset<MAXN> vis;
        deque<int> dq;
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            if (!vis[nums[i]]) {
                vis[nums[i]] = true;
                curSum += nums[i];
                dq.push_back(nums[i]);
            }
            else {
                while (vis[nums[i]]) {
                    vis[dq.front()] = false;
                    curSum -= dq.front();
                    dq.pop_front();
                }
                vis[nums[i]] = true;
                curSum += nums[i];
                dq.push_back(nums[i]);
            }
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};