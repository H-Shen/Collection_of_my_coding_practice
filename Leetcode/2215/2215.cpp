class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> unset1(nums1.begin(),nums1.end());
        unordered_set<int> unset2(nums2.begin(),nums2.end());
        vector<int> v1, v2;
        for (auto&i : unset1) {
            if (unset2.count(i) == 0) v1.emplace_back(i);
        }
        for (auto&i : unset2) {
            if (unset1.count(i) == 0) v2.emplace_back(i);
        }
        return vector<vector<int>>{v1,v2};
    }
};