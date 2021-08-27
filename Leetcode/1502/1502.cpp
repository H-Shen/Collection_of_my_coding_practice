class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if (arr.size() <= 2) return true;
        sort(arr.begin(), arr.end());
        int diff = arr[0] - arr[1];
        int n = (int)arr.size();
        for (int i = 1; i < n; ++i) {
            if (diff != arr[i-1] - arr[i]) {
                return false;
            }
        }
        return true;
    }
};