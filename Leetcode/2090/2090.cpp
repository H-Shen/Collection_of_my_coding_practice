using ll = long long;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = (int)nums.size();
        int temp = 2*k+1;
        if (n < temp) {
            return vector<int>(n, -1);
        }
        vector<int> ans(n);
        for (int i = 0; i < k; ++i) ans[i] = -1;
        for (int i = n-1; i >= n-k; --i) ans[i] = -1;
        ll sum = 0;
        for (int i = 0; i < temp; ++i) {
            sum += nums[i];
        }
        for (int i = k; i < n-k; ++i) {
            ans[i] = (int)(sum / temp);
            if (i+k+1 < n) {
                sum -= nums[i-k];
                sum += nums[i+k+1];
            }
        }
        return ans;
    }
};