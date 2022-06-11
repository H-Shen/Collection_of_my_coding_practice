using ll = long long;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = (int)nums.size();
        vector<ll> pre(n+1);
        pre[1] = nums[0];
        for (int i = 2; i <= n; ++i) {
            pre[i] = pre[i-1] + (ll)nums[i-1];
        }
        ll a, b;
        ll counter = 0;
        int left, right, mid, ans;
        for (int l = 1; l <= n; ++l) {
            a = pre[l-1];
            b = l-1;
            left = l;
            right = n;
            ans = numeric_limits<int>::min();
            while (left <= right) {
                mid = left + ((right - left) >> 1);
                if ((pre[mid] - a) * (mid - b) < k) {
                    ans = max(ans, mid);
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            if (ans != numeric_limits<int>::min()) {
                counter += (ll)(ans - l + 1);
            }
        }
        return counter;
    }
};