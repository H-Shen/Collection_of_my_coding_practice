class Solution {
public:
    vector<int> pre;
    int rangeSum(int l, int r) {
        if (l == 0) {
            return pre[r];
        }
        return pre[r]-pre[l-1];
    }
    int findMiddleIndex(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 1) {
            return 0;
        }
        vector<int>().swap(pre);
        pre.resize(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i-1] + nums[i];
        }
        if (0 == rangeSum(1, n-1)) {
            return 0;
        }
        for (int middleIndex = 1; middleIndex < n - 1; ++middleIndex) {
            if (rangeSum(0,middleIndex-1) == rangeSum(middleIndex+1,n-1)) {
                return middleIndex;
            }
        }
        if (rangeSum(0, n-2) == 0) {
            return n-1;
        }
        return -1;
    }
};