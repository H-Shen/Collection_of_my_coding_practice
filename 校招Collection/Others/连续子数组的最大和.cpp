// https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int currentSum = 0, maxSum = 0, interval = -2147483648;
        int n = array.size();
        for (int i = 0; i < n; i++) {
            currentSum += array[i];

            if (array[i] <= 0 && array[i] > interval) {
                interval = array[i];
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