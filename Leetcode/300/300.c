int lengthOfLIS(int* nums, int numsSize){
    int* dp = (int*)malloc(numsSize*sizeof(int));
    for (int i = 0; i < numsSize; ++i) {
        dp[i] = 1;
    }
    for (int i = 0; i < numsSize-1; ++i) {
        for (int j = i+1; j < numsSize; ++j) {
            if (nums[j] > nums[i]) {
                if (dp[j] < dp[i] + 1) {
                    dp[j] = dp[i] + 1;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (ans < dp[i]) {
            ans = dp[i];
        }
    }
    free(dp);
    dp = NULL;
    return ans;
}