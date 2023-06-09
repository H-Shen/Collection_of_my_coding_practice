class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = (int)nums.size();
        int pos_1, pos_n;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) pos_1 = i;
            if (nums[i] == n) pos_n = i;
        }
        if (pos_1 < pos_n) {
            return pos_1+(n-pos_n-1);
        }
        else if (pos_1 == pos_n) {
            return 0;
        }
        return pos_1+(n-pos_n-1)-1;
    }
};