class Solution {
public:
    inline
    int rangeSum(vector<int>&pre, int l, int r) {
        if (l == 0) {
            return pre[r];
        }
        return pre[r] - pre[l-1];
    }
    bool splitArray(vector<int>& nums) {
        int n = (int)nums.size();
        if (n <= 6) {
            return false;
        }
        vector<int> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i-1] + nums[i];
        }
        unordered_map<int, unordered_set<int>> unmap;
        int rs;
        // O(n^2)
        for (int i = 1; i < n-5; ++i) {
            for (int j = i+2; j <= n-4; ++j) {
                rs = rangeSum(pre, 0, i-1);
                if (rs == rangeSum(pre, i+1, j-1)) {
                    unmap[rs].insert(j);   
                }
            }
        }
        // O(n^2)
        for (int j = 3; j <= n-4; ++j) {
            for (int k = j+2; k < n-1; ++k) {
                rs = rangeSum(pre, j+1, k-1);
                if (rs == rangeSum(pre, k+1,n-1)) {
                    auto iter = unmap.find(rs);
                    if (iter != unmap.end() && iter->second.find(j) != iter->second.end()) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};