class Solution {
public:
    int pivotIndex(vector<int> &nums) {

        if (nums.empty()) {
            return -1;
        } else if (nums.size() == 1) {
            return 0;
        }

        vector<int> leftSum(nums.size()), rightSum(nums.size());

        int sum = 0;
        int len = static_cast<int>(nums.size());
        int i;

        for (i = 0; i < len; ++i) {
            sum += nums[i];
            leftSum[i] = sum;
        }

        sum = 0;
        for (i = len - 1; i >= 0; --i) {
            sum += nums[i];
            rightSum[i] = sum;
        }

        int leftSumVal, rightSumVal;
        for (i = 0; i < len; ++i) {
            if (i == 0) {
                leftSumVal = 0;
                rightSumVal = rightSum[1];
            } else if (i == len - 1) {
                leftSumVal = leftSum[i - 1];
                rightSumVal = 0;
            } else {
                leftSumVal = leftSum[i - 1];
                rightSumVal = rightSum[i + 1];
            }
            if (leftSumVal == rightSumVal) {
                return i;
            }
        }

        return -1;
    }
};