class Solution {
public:
    int twoSumSmallerThanK(vector<int>& nums, int rightIndex, int target) {
        int l = 0;
        int r = rightIndex;
        int counter = 0;
        int temp;
        while (l < r) {
            temp = nums[l] + nums[r];
            if (temp >= target) {
                --r;
            }
            else {
                counter += r - l;
                ++l;
            }
        }
        return counter;
    }
    // O(n^2)
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (n < 3) {
            return 0;
        }
        sort(nums.begin(),nums.end());
        int counter = 0;
        for (int k = 2; k < n; ++k) {
            counter += twoSumSmallerThanK(nums, k-1, target - nums[k]);
        }
        return counter;
    }
};