class Solution {
public:
    Solution() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        if (arr.size() == 1) return 1;
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        int n = (int)arr.size();
        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i-1]+1) arr[i] = arr[i-1]+1;
        }
        return arr.back();
    }
};