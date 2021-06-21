class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = (int)timeSeries.size();
        int ans = 0;
        if (n == 1) {
            ans += duration;
        }
        else {
            for (int i = 0; i < n; ++i) {
                if (i == n - 1) {
                    ans += duration;
                    continue;
                }
                if (timeSeries[i+1] > timeSeries[i] + duration - 1) {
                    ans += duration;
                } else {
                    ans += timeSeries[i+1] - timeSeries[i];
                }
            }   
        }
        return ans;
    }
};