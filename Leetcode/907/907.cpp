class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        using ll = long long;
        constexpr int MOD = 1e9+7;
        int ans = 0;
        int n = (int)arr.size();
        stack<int> s;
        int curVal, index, l, r;
        for (int i = 0; i <= n; ++i) {
            if (i < n) {
                curVal = arr[i];
            } else {
                curVal = 0;
            }
            while (!s.empty() && curVal < arr[s.top()]) {
                index = s.top();
                s.pop();
                if (s.empty()) {
                    l = index + 1;
                } else {
                    l = index - s.top();
                }
                r = i - index;
                ans = ((ll)ans + (ll)l * r * arr[index]) % MOD;
            }
            s.push(i);
        }
        return ans;
    }
};