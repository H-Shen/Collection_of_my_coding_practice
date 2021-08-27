class Solution {
public:
    int getCost(int src, int dest) {
        return ((dest - src) % 2 == 0) ? 0 : 1;
    }
    int minCostToMoveChips(vector<int>& position) {
        unordered_set<int> pos(position.begin(), position.end());
        int minCost = numeric_limits<int>::max();
        int currentCost;
        for (const auto &i : pos) {
            currentCost = 0;
            for (const auto &j : position) {
                currentCost += getCost(j, i);
            }
            minCost = min(minCost, currentCost);
        }
        return minCost;
    }
};