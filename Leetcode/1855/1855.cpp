class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n = (int)nums1.size();
        int m = (int)nums2.size();
        for (int i = 0; i < n; ++i) {
            if (nums1[i] > nums2.front()) {
                continue;
            }
            auto it = upper_bound(nums2.begin()+i, nums2.end(),nums1[i],greater<>());
            --it;
            int j = it - nums2.begin();
            if (i <= j) {
                ans = max(ans, abs(j-i));
            }
        }
        return ans;
    }
};