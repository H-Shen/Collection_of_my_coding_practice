class Solution {
public:
    // https://leetcode-cn.com/problems/gas-station/solution/shou-hua-tu-jie-liang-ge-guan-jian-jie-lun-de-jian/
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = (int)gas.size();
        int totalGas = 0;
        int totalCost = 0;
        int currentGas = 0;
        int result = 0;
        for (int i = 0; i < n; ++i) {
            totalGas += gas[i];
            totalCost += cost[i];
            currentGas = currentGas + gas[i] - cost[i];
            if (currentGas < 0) {
                currentGas = 0;
                result = i+1;   // abandon all previous stations
            }
        }
        if (totalGas < totalCost) {
            return -1;
        }
        return result;
    }
};