class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = (int)nums.size();
        if (n > 1) {
            for (int i = 0; i < n-1; ) {
                if (nums[i] == nums[i+1]) {
                    nums[i] *= 2;
                    nums[i+1] = 0;
                    i += 2;
                }
                else {
                    ++i;
                }
            }
        }
        stable_partition(nums.begin(),nums.end(),[](const int&x){ return x != 0;});
        return nums;
    }
};