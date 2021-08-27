class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ans = 0;
        int counter = 0;
        int n = (int)arr.size();
        constexpr int MAXN = 5000;
        for (int i = 0; i < n; ++i) {
            if (ans + arr[i] > MAXN) {
                break;
            }
            ans += arr[i];
            ++counter;
        }
        return counter;
    }
};