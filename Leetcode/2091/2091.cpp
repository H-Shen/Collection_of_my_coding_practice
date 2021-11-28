class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        const auto [i,j] = minmax_element(nums.begin(),nums.end());
        int l = i - nums.begin();
        int r = j - nums.begin();
        if (l > r) swap(l, r);
        int ans = numeric_limits<int>::max();
        int n = (int)nums.size();
        // from left
        ans = min(r+1, ans);
        // from right
        ans = min(n-l, ans);
        // from left and right
        if (l != r) {
            ans = min(ans, (l+1)+(n-r));
        }
        return ans;
    }
};