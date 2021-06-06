class Solution {
public:
    vector<int> dp;
    int n;
    int solve(int i, int bitmask, const vector<int>&v1, const vector<int>&v2) {
        if (i >= n) {
            return 0;
        }
        if (dp.at(bitmask) != -1) {
            return dp.at(bitmask);
        }
        for (int j = 0; j < n; ++j) {
            if ((bitmask & (1 << j)) == 0) {
                if (dp.at(bitmask) == -1) {
                    dp.at(bitmask) = (v1.at(i)^v2.at(j))+solve(i+1,bitmask+(1<<j),v1,v2);
                }
                else {
                    dp.at(bitmask) = min(dp.at(bitmask),(v1.at(i)^v2.at(j))+solve(i+1,bitmask+(1<<j),v1,v2));
                }
            }
        }
        return dp.at(bitmask);
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        vector<int>().swap(dp);
        n = (int)nums1.size();
        dp.resize(1<<n, -1);
        return solve(0,0,nums1,nums2);
    }
};