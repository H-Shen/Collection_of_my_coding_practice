class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if (k == 0) {
            return nums[0];
        }
        int n = (int)nums.size();
        if (k == 1) {
            if (n == 1) {
                return -1;
            }
            return nums[1];
        }
        if (k > n) {
            if ((k-n)&1) {
                return *max_element(nums.begin(),nums.end());
            }
            else {
                if (n > 1) {
                    return *max_element(nums.begin(),nums.end());
                }
                return -1;
            }
        }
        else {
            int maxVal = *max_element(nums.begin(),nums.begin()+k-1);
            if (n >= k+1 && nums[k] > maxVal) {
                return nums[k];
            }
            return maxVal;
        }
    }
};