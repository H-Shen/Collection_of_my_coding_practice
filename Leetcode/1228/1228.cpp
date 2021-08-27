class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = (int)arr.size();
        int d = (arr.back() - arr.front()) / n;
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] + d != arr[i+1]) {
                return arr[i]+d;
            }
        }
        return arr[0];  // d = 0
    }
};