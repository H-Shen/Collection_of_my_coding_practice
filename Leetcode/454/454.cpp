class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = (int)nums1.size();
        unordered_map<int,int> unmap1,unmap2;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ++unmap1[nums1[i]+nums2[j]];
                ++unmap2[nums3[i]+nums4[j]];
            }
        }
        int ans = 0;
        for (const auto &[k,v] : unmap1) {
            if (unmap2.find(-k) != unmap2.end()) {
                ans += v*unmap2[-k];
            }
        }
        return ans;
    }
};