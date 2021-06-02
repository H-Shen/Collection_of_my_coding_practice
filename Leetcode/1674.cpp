class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        constexpr int MAXN = 1e5*2+5;
        int diff[MAXN]{};
        int n = (int)nums.size();
        for (int i = 0; i < (n>>1); ++i) {
            diff[2] += 2;
            --diff[1+min(nums[i],nums[n-1-i])];
            --diff[min(nums[i],nums[n-1-i])+max(nums[i],nums[n-1-i])];
            ++diff[min(nums[i],nums[n-1-i])+max(nums[i],nums[n-1-i])+1];
            ++diff[max(nums[i],nums[n-1-i])+1+limit];
        }
        int ans = numeric_limits<int>::max();
        int temp = 0;
        for (int i = 2; i <= (limit<<1); ++i) {
            temp += diff[i];
            ans = min(ans, temp);
        }
        return ans;
    }
};