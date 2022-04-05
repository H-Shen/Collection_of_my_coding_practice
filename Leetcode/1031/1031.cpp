class Solution {
public:
    int rangeSum(vector<int>&pre, int l, int r) {
        if (l == 0) {
            return pre[r];
        }
        return pre[r] - pre[l-1];
    }
    // O(n): rangeSum + sliding window + greedy
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = (int)nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i-1] + nums[i];
        }
        
        // obtain max-range-sum of 'secondLen' length from left to right
        vector<int> maxFromLeft(n);
        maxFromLeft[secondLen - 1] = rangeSum(pre, 0, secondLen - 1);
        for (int i = secondLen; i < n; ++i) {
            maxFromLeft[i] = max(maxFromLeft[i-1], rangeSum(pre, i - (secondLen-1),i));
        }
        // obtain max-range-sum of 'secondLen' length from right to left
        vector<int> maxFromRight(n);
        maxFromRight[n - secondLen] = rangeSum(pre, n - secondLen, n - 1);
        for (int i = n - secondLen - 1; i >= 0; --i) {
            maxFromRight[i] = max(maxFromRight[i+1], rangeSum(pre, i, i + secondLen - 1));
        }
        int maxVal = 0;
        for (int i = 0; i + firstLen <= n; ++i) {
            if (i >= secondLen) {
                maxVal = max(maxVal, rangeSum(pre, i, i + firstLen - 1) + maxFromLeft[i-1]);
            }
            if (i + firstLen - 1 + secondLen < n) {
                maxVal = max(maxVal, rangeSum(pre, i, i + firstLen - 1) + maxFromRight[i+firstLen]);
            }
        }
        return maxVal;
    }
};