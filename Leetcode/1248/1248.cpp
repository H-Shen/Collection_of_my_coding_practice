class Solution {
public:
    // prefix sum + binary search  O(nlogn)
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = (int)nums.size();
        for (auto& i : nums) {
            i = (i & 1) ? 1 : 0;
        }
        vector<int> pre(n+1);
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i-1] + nums[i-1];
        }
        int counter = 0;
        for (int left = 1; left <= n; ++left) {
            int temp = pre[left-1] + k;
            if (binary_search(pre.begin(),pre.end(),temp)) {
                auto p = equal_range(pre.begin(),pre.end(),temp);
                counter += (int)(p.second - p.first);
            }
        }
        return counter;
    }
};
