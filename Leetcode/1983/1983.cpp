class Solution {
public:
    int widestPairOfIndices(vector<int>& nums1, vector<int>& nums2) {
        int n = (int)nums1.size();
        vector<int> pre1(n+1);
        for (int i = 1; i < n+1; ++i) {
            pre1[i] = pre1[i-1]+nums1[i-1]; 
        }
        vector<int> pre2(n+1);
        for (int i = 1; i < n+1; ++i) {
            pre2[i] = pre2[i-1]+nums2[i-1];
        }
        unordered_map<int,vector<int>> unmap;
        for (int i = 0; i < n+1; ++i) {
            unmap[pre1[i]-pre2[i]].emplace_back(i);
        }
        int ans = 0;
        for (const auto &[k,v] : unmap) {
            if (v.size() > 1) {
                ans = max(v.back()-v.front(), ans);
            }
        }
        return ans;
    }
};