class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int counter = 0;
        int n = (int)costs.size();
        for (int i = 0; i < n; ++i) {
            coins -= costs[i];
            if (coins < 0) {
                break;
            }
            ++counter;
        }
        return counter;
    }
};