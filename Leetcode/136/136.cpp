class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        if (n == 1)
        	return nums[0];
    	for (;n >= 2; n--)
        	nums[n - 2] = nums[n - 2] ^ nums[n - 1];
    	return nums[n - 1];
    }
};