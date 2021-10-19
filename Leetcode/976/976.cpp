class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = (int)nums.size();
        sort(nums.begin(),nums.end());
        for (int i = n-1; i >= 2; --i) {
            int c = nums[i];
            int a = nums[i-2];
            int b = nums[i-1];
            if (a + b > c) {
                return a+b+c;
            }
        }
        return 0;
    }
};