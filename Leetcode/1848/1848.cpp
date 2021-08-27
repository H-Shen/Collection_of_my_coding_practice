class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        constexpr int INF = 0x3f3f3f3f;
        int n = (int)nums.size();
        int result = INF;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                result = min(result, abs(i-start));
            }
        }
        return result;
    }
};