class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = (int)nums1.size();
        int m = (int)nums2.size();
        int ans = -1;
        if (m & 1) {
            for (int& i : nums1) {
                if (ans == -1) {
                    ans = i;
                }
                else {
                    ans ^= i;
                }
            }   
        }
        else {
            ans = 0;
        }
        if (n & 1) {
            for (int& i : nums2) {
                ans ^= i;
            }
        }
        else {
            ans ^= 0;
        }
        return ans;
    }
};