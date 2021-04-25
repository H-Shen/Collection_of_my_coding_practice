class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = (int)prices.size();
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = prices[i];
            for (int j = i + 1; j < n; ++j) {
                if (prices[j] <= prices[i]) {
                    result[i] = prices[i] - prices[j];
                    break;
                }
            }
        }
        return result;
    }
};