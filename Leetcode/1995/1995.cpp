class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        constexpr int MAXN = 305;
        vector<int> unmap[MAXN];
        memset(unmap, 0, sizeof unmap);
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            unmap[nums[i]].emplace_back(i);
        }
        int ans = 0;
        int temp;
        for (int a = 0; a < n-2; ++a) {
            for (int b = a+1; b < n-1; ++b) {
                for (int c = b+1; c < n; ++c) {
                    int temp = nums[a]+nums[b]+nums[c];
                    if (!unmap[temp].empty()) {
                        if (c < unmap[temp].front()) {
                            ans += (int)unmap[temp].size();
                        }
                        else if (c > unmap[temp].back()) {
                            continue;
                        }
                        else {
                            auto iter = --upper_bound(unmap[temp].begin(),unmap[temp].end(),c);
                            ans += (int)unmap[temp].size() - 1 - (int)(iter - unmap[temp].begin());
                        }
                    }
                }
            }
        }
        return ans;
    }
};