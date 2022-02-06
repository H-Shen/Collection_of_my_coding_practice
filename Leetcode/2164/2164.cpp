class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> even,odd;
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                odd.emplace_back(nums[i]);
            }
            else {
                even.emplace_back(nums[i]);
            }
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end(),greater<>());
        vector<int> ans(n);
        int i = 0, j = 0;
        for (int index = 0; index < n; ++index) {
            if (index & 1) {
                ans[index] = odd[i];
                ++i;
            }
            else {
                ans[index] = even[j];
                ++j;
            }
        }
        return ans;
    }
};