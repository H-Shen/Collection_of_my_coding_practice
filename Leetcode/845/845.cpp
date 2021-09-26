class Solution {
public:
    // O(n) space
    int longestMountain(vector<int>& arr) {
        int n = (int)arr.size();
        if (n < 3) {
            return 0;
        }
        vector<int> dp1(n, 1);
        for (int i = 1; i < n; ++i) {
            if (arr[i-1] < arr[i]) {
                dp1[i] = dp1[i-1] + 1;
            }
        }
        vector<int> dp2(n, 1);
        for (int i = n-2; i >= 0; --i) {
            if (arr[i] > arr[i+1]) {
                dp2[i] = dp2[i+1] + 1;
            }
        }
        int maxLength = 0;
        for (int i = 1; i <= n-2; ++i) {
            if (dp1[i] == 1 || dp2[i] == 1) {
                continue;
            }
            maxLength = max(maxLength, dp1[i]+dp2[i]-1);
        }
        return maxLength;
    }
};