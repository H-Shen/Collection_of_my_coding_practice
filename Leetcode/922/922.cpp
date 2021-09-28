class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = (int)nums.size();
        int j = 1;
        for (int i = 0; i < n; i += 2) {
            if (nums[i] & 1) {
                for (; j < n; j += 2) {
                    if (!(nums[j] & 1)) {
                        swap(nums[i],nums[j]);
                        break;
                    }
                }
            }
        }
        return nums;
    }
};