class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> leftMax(n);
        leftMax[0] = nums[0];
        int temp = nums[0];
        for (int i = 1; i < n; ++i) {
            temp = max(temp, nums[i]);
            leftMax[i] = temp;
        }
        vector<int> rightMin(n);
        rightMin[n-1] = nums[n-1];
        temp = nums[n-1];
        for (int i = n - 2; i >= 0; --i) {
            temp = min(temp, nums[i]);
            rightMin[i] = temp;
        }
        for (int i = 0; i < n - 1; ++i) {
            if (leftMax[i] <= rightMin[i+1]) {
                return i+1;
            }
        }
        return -1;
    }
};