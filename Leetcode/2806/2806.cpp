class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int roundedAmount;
        int diff;
        int minDiff = numeric_limits<int>::max();
        int ans = 0;
        for (roundedAmount = 0; roundedAmount <= 100; roundedAmount += 10) {
            diff = abs(roundedAmount - purchaseAmount);
            minDiff = min(minDiff, diff);
        }
        for (roundedAmount = 0; roundedAmount <= 100; roundedAmount += 10) {
            diff = abs(roundedAmount - purchaseAmount);
            if (diff == minDiff) {
                ans = max(ans, roundedAmount);
            }
        }
        return 100-ans;
    }
};