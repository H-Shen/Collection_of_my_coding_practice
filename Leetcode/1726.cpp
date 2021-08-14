class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = (int)nums.size();
        if (n < 4) return 0;
        unordered_map<int,int> unmap;
        for (int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                ++unmap[nums[i]*nums[j]];
            }
        }
        int ans = 0;
        for (const auto &[k,v] : unmap) {
            if (v > 1) ans += (v*(v-1))<<2;
        }
        return ans;
    }
};