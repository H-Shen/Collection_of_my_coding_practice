class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> vec;
        set_intersection(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),back_inserter(vec));
        if (!vec.empty()) {
            return vec.front();
        }
        int minVal1 = nums1.front();
        int minVal2 = nums2.front();
        if (minVal1 > minVal2) swap(minVal1, minVal2);
        return minVal1*10+minVal2;
    }
};