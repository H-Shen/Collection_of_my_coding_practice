class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        multiset<int> ms(nums.begin(),nums.end());
        int cnt = 0;
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            auto iter = ms.upper_bound(nums[i]);
            if (iter == ms.end()) {
                ms.erase(ms.begin());
            }
            else {
                ++cnt;
                ms.erase(iter);
            }
        }
        return cnt;
    }
};