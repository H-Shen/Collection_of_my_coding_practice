class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = (int)nums.size();
        int total = pow(2,n);
        int sum = 1;
        for (int i = 0; i < total; ++i) {
            bitset<32> bs(i);
            int cur = -1;
            for (int j = 0; j < n; ++j) {
                if (bs[j] != 0) {
                    if (cur == -1) {
                        cur = nums[j];
                    } else {
                        cur = cur ^ nums[j];
                    }
                }
            }
            sum += cur;
        }
        return sum;
    }
};