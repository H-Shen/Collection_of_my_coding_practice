class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double totalTime = 0.0;
        int n = (int)customers.size();
        int currentTime = 0;
        int waitingTime;
        for (int i = 0; i < n; ++i) {
            if (currentTime < customers[i][0]) {
                currentTime = customers[i][0] + customers[i][1];
                waitingTime = customers[i][1];
            }
            else {
                currentTime = currentTime + customers[i][1];
                waitingTime = currentTime - customers[i][0];
            }
            totalTime += waitingTime;
        }
        return totalTime / n;
    }
};