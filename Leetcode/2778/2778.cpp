class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = (int)nums.size();
        int s = 0;
        for (int i = 0; i < n; ++i) {
            if (n % (i+1) == 0) s += nums[i]*nums[i];
        }
        return s;
    }
};