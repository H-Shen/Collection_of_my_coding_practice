using ll = long long;

class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        unordered_map<ll, int> unmap;
        int n = (int)nums2.size();
        for (int j = 0; j < n - 1; ++j) {
            for (int k = j+1; k < n; ++k) {
                ++unmap[(ll)nums2[j]*nums2[k]];
            }
        }
        ll temp;
        for (const auto &i : nums1) {
            temp = (ll)i*i;
            auto iter = unmap.find(temp);
            if (iter != unmap.end()) {
                ans += iter->second;
            }
        }
        return ans;
    }
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        return solve(nums1,nums2)+solve(nums2,nums1);
    }
};