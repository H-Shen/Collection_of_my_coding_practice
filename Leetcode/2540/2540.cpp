class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vec;
        set_intersection(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),back_inserter(vec));
        return vec.empty() ? -1 : vec.front();
    }
};