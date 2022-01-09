class Solution {
public:
    int rangeSum(vector<int>& pre, int l, int r) {
        if (l == 0) {
            return pre[r];
        }
        return pre[r] - pre[l-1];
    }
    int rangeSum2(vector<int>& pre, int l1, int r1, int l2, int r2) {
        return rangeSum(pre, l1, r1) + rangeSum(pre, l2, r2);
    }
    int minSwaps(vector<int>& nums) {
        int n = (int)nums.size();
        int counter = (int)count(nums.begin(),nums.end(),1);
        if (counter == 0) return 0;
        int result = numeric_limits<int>::max();
        vector<int> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i-1] + nums[i];
        }
        // case 1:
        for (int r = counter-1, l = 0; r < n; ++r, ++l) {
            result = min(result, counter - rangeSum(pre,l,r));
        }
        // case 2:
        if (counter > 1) {
            for (int l2 = n-counter, r1 = -1; l2 < n; ++l2, ++r1) {
                int r2 = n-1;
                int l1 = 0;
                if (l2 == n-counter) continue;
                result = min(result, counter - rangeSum2(pre, l1, r1, l2, r2));
            }
        }
        
        return result;
    }
};