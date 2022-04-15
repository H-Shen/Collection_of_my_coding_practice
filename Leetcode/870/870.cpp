class Solution {
public:
    // greedy
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> ms(nums1.begin(),nums1.end());
        int n = (int)nums1.size();
        vector<int> result(n);
        multiset<int>::iterator it1, it2;
        for (int i = 0; i < n; ++i) {
            // try to find the element in 'ms' such that it is bigger than and the closest to nums2[i]
            it1 = ms.upper_bound(nums2[i]);
            if (it1 == ms.end()) {
                it2 = ms.begin(); 
                result[i] = *it2;
                ms.erase(it2);
            }
            else {
                result[i] = *it1;
                ms.erase(it1);
            }
        }
        return result;
    }
};