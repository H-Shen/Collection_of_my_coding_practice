class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> positive;
        vector<int> negative;
        for (auto&i : nums) {
            if (i > 0) positive.emplace_back(i);
            else negative.emplace_back(i);
        }
        int index = 0;
        vector<int> ans(n);
        for (int i = 0; i < n;) {
            ans[i++] = positive[index];
            ans[i++] = negative[index];
            ++index;
        }
        return ans;
    }
};