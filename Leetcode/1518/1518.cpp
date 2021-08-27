class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int emptyBottles = 0;
        while (true) {
            ans += numBottles;
            emptyBottles += numBottles;
            if (emptyBottles < numExchange) break;
            numBottles = emptyBottles / numExchange;
            emptyBottles %= numExchange;
        }
        return ans;
    }
};