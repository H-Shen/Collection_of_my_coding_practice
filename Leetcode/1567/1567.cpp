class Solution {
public:
    int f(vector<int>& nums, int l, int r) {
        int ans = 0;
        // dp from left
        int negativeCounter = 0;
        int indexOfFirstNegative;
        if (nums[l] > 0) {
            ans = max(ans, 1);
        }
        else {
            ++negativeCounter;
            indexOfFirstNegative = l;
        }
        for (int i = l+1; i <= r; ++i) {
            if (nums[i] < 0) {
                ++negativeCounter;
                if (negativeCounter == 1) {
                    indexOfFirstNegative = i;
                }
            }
            ans = (negativeCounter & 1) ? max(ans,i-indexOfFirstNegative) : max(ans,i-l+1);
        }
        // dp from right
        negativeCounter = 0;
        if (nums[r] > 0) {
            ans = max(ans, 1);
        }
        else {
            ++negativeCounter;
            indexOfFirstNegative = r; 
        }
        for (int i = r-1; i >= l; --i) {
            if (nums[i] < 0) {
                ++negativeCounter;
                if (negativeCounter == 1) {
                    indexOfFirstNegative = i;
                }
            }
            ans = (negativeCounter & 1) ? max(ans, indexOfFirstNegative-i) : max(ans, r-i+1);
        }
        return ans;
    }
    int getMaxLen(vector<int>& nums) {
        int ans = 0;
        int n = (int)nums.size();
        int l = -1;
        int r = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                if (l == -1) {
                    l = i;
                    r = i;
                }
                else {
                    ++r;
                }
            }
            else if (l != -1) {
                ans = max(ans, f(nums, l, r));
                l = -1;
                r = -1;
            }
        }
        if (l != -1) {
            ans = max(ans, f(nums, l, r));
        }
        return ans;
    }
};