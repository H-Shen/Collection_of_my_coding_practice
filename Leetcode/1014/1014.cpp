class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
        // v[i] + v[j] + i - j = s
        // (v[i] + i) + (v[j] - j) = s
        int n = (int)v.size();
        vector<int> A(n);
        for (int j = 0; j < n; ++j) {
            A[j] = v[j] - j;
        }
        for (int j = n-2; j >= 0; --j) {
            A[j] = max(A[j], A[j+1]);
        }
        int ans = -1;
        for (int i = 0; i < n - 1; ++i) {
            ans = max(ans, v[i]+i+A[i+1]);
        }
        return ans;
    }
};