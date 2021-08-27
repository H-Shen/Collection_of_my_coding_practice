class Solution {
public:
    vector<int> prefixSum;
    int rangeSum(int l, int r) {
        if (l == 0) return prefixSum[r];
        return prefixSum[r] - prefixSum[l - 1];
    }
    int sumOddLengthSubarrays(vector<int>& arr) {
        partial_sum(arr.begin(), arr.end(), back_inserter(prefixSum));
        int sum = 0;
        int n = (int)arr.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if ((j - i + 1) % 2 != 0) {
                    sum += rangeSum(i, j);
                }
            }
        }
        return sum;
    }
};