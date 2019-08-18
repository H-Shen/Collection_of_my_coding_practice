class Solution {
public:
    int maxSubArray(vector<int> &A) {

        if (A.empty()) {
            return numeric_limits<int>::min();
        }

        int currentSum = 0, maxSum = 0, interval = A[0];
        int n = A.size();
        for (int i = 0; i < n; i++) {
            currentSum += A[i];

            if (A[i] <= 0 && A[i] > interval) {
                interval = A[i];
            }

            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
            else if (currentSum < 0) {
                currentSum = 0;
            }
        }

        if (maxSum == 0) {
            return interval;
        }
        return maxSum;
    }
};