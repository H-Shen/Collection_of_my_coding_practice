class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double result;
        deque<double> dq;
        int i;
        double currentSum = 0.0;
        for (i = 0; i < k; ++i) {
            currentSum += nums.at(i);
        }
        result = currentSum / k;
        int n = (int)nums.size();
        for (int j = 0; i < n; ++i, ++j) {
            currentSum += nums.at(i) - nums.at(j);
            result = max(result, currentSum / k);
        }
        return result;
    }
};