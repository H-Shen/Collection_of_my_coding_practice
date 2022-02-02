using ll = long long;
constexpr ll MOD = 1e9+7;

class Solution {
public:
    // pre[r] - pre[l-1] is odd
    // 1. pre[l-1] is odd, pre[r] is even. pre[left] is odd, pre[right] is even (left < right)
    // 2. pre[l-1] is even, pre[r] is odd. pre[left] is even, pre[right] is odd (left < right)
    int numOfSubarrays(vector<int>& arr) {
        int n = (int)arr.size();
        vector<int> pre(n+1);
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i-1] + arr[i-1];
        }
        vector<int> evenFromRight(n);
        vector<int> oddFromRight(n);
        if (pre[n] & 1) {
            oddFromRight[n-1] = 1;
        } else {
            evenFromRight[n-1] = 1;
        }
        for (int i = n-2; i >= 0; --i) {
            if (pre[i+1] & 1) {
                oddFromRight[i] = oddFromRight[i+1] + 1;
                evenFromRight[i] = evenFromRight[i+1];
            }
            else {
                oddFromRight[i] = oddFromRight[i+1];
                evenFromRight[i] = evenFromRight[i+1] + 1;
            }
        }
        ll counter = 0;
        for (int i = 0; i < n; ++i) {
            if (pre[i] & 1) {
                counter = (counter + evenFromRight[i]) % MOD;
            }
            else {
                counter = (counter + oddFromRight[i]) % MOD;
            }
        }
        return counter % MOD;
    }
};