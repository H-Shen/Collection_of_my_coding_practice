class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // greedy, obtain all diff[i] such that diff[i] > 0
        // p[l] - p[r] = (p[l]-p[l-1])+(p[l-1]-p[l-2])+...+(p[r+1]-p[r])
        //             = diff[l] + diff[l-1] + ... + diff[r+1]
        //             = sigma(r+1 to l) diff
        int n = (int)prices.size();
        if (n == 1) {
            return 0;
        }
        int ans = 0;
        int temp;
        for (int i = 1; i < n; ++i) {
            temp = prices[i] - prices[i-1];
            if (temp > 0) {
                ans += temp;
            }
        }
        return ans;
    }
};