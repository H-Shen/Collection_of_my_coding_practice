class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1(nums1.begin(),nums1.end());
        unordered_set<int> n2(nums2.begin(),nums2.end());
        int c1 = 0, c2 = 0;
        for (size_t i = 0; i != nums1.size(); ++i) {
            if (n2.count(nums1[i]) > 0) {
                ++c1;
            }
        }
        for (size_t i = 0; i != nums2.size(); ++i) {
            if (n1.count(nums2[i]) > 0) {
                ++c2;
            }
        }
        return vector<int>{c1,c2};
    }
};