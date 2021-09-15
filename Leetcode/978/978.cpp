class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = (int)arr.size();
        vector<int> dp1(n);
        dp1[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (i & 1) {
                if (arr[i-1] < arr[i]) {
                    dp1[i] = dp1[i-1] + 1;
                }
                else {
                    dp1[i] = 1;
                }
            }
            else {
                if (arr[i-1] > arr[i]) {
                    dp1[i] = dp1[i-1] + 1;
                }
                else {
                    dp1[i] = 1;
                }
            }
        }
        vector<int> dp2(n);
        dp2[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (i & 1) {
                if (arr[i-1] > arr[i]) {
                    dp2[i] = dp2[i-1] + 1;
                }
                else {
                    dp2[i] = 1;
                }
            }
            else {
                if (arr[i-1] < arr[i]) {
                    dp2[i] = dp2[i-1] + 1;
                }
                else {
                    dp2[i] = 1;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, max(dp1[i], dp2[i]));
        }
        return ans;
    }
};