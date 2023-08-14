class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int cnt = (int)unordered_set<int>(nums.begin(),nums.end()).size();
        int ans = 0;
        int n = (int)nums.size();
        bool flag;
        int j;
        for (int i = 0; i < n; ++i) {
            unordered_set<int> unset;
            flag = false;
            for (j = i; j < n; ++j) {
                unset.insert(nums[j]);
                if ((int)unset.size() == cnt) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                for (; j < n; ++j) {
                    if ((int)unset.size() > cnt) break;
                    else {
                        ++ans;
                    }
                    unset.insert(nums[j]);
                }
            }
        }
        return ans;
    }
};