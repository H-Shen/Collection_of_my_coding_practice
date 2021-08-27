class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size();
        if (n == 1) return 0;
        vector<int> minFromLeft(n);
        minFromLeft[0] = prices[0];
        for (int i = 1; i < n; ++i) {
            minFromLeft[i] = min(prices[i], minFromLeft[i-1]);
        }
        vector<int> maxFromRight(n);
        maxFromRight[n-1] = prices[n-1];
        for (int i = n - 2; i >= 0; --i) {
            maxFromRight[i] = max(prices[i], maxFromRight[i+1]);
        }
        int maxProfit = 0;
        int temp;
        for (int i = 0; i < n-1; ++i) {
            temp = maxFromRight[i+1] - minFromLeft[i];
            if (temp >= 0) {
                maxProfit = max(maxProfit, temp);
            }
        }
        return maxProfit;
    }
};