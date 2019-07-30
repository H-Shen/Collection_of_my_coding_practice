// https://www.nowcoder.com/practice/ab79a29848d14228bb8e6b1af1c78bb7

class MaxSum {
public:
    int getMaxSum(vector<int> A, int n) {
        // write code here
        int currentSum = 0, maxSum = 0, interval = INT_MIN;
        for (int i = 0; i < n; i++) {
            currentSum += A[i];

            if (A[i] <= 0 && A[i] > interval) {
                interval = A[i];
            }

            if (currentSum > maxSum)
                maxSum = currentSum;
            else if (currentSum < 0)
                currentSum = 0;
        }

        if (maxSum == 0)
            return interval;
        return maxSum;
    }
};