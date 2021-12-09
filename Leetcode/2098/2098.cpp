using ll = long long;

class Solution {
public:
    void getPrefixSum(vector<ll>& A) {
        int n = (int)A.size();
        for (int i = 1; i < n; ++i) {
            A[i] += A[i-1];
        }
    }
    // prefix sum of first k elements
    ll pre(int k, vector<ll>&A) {
        if (k == 0) return 0;
        return A[k-1];
    }
    long long largestEvenSum(vector<int>& nums, int k) {
        int n = (int)nums.size();
        vector<ll> odd, even;
        for (int i = 0; i < n; ++i) {
            if (nums[i] & 1) odd.emplace_back(nums[i]);
            else even.emplace_back(nums[i]);
        }
        sort(odd.begin(),odd.end(),greater<>());
        sort(even.begin(),even.end(),greater<>());
        // prefix sum
        getPrefixSum(odd);
        getPrefixSum(even);
        ll result = -1;
        int a,b;
        int oddNumbers = (int)odd.size();
        int evenNumbers = (int)even.size();
        // k=a+b, a odd numbers and b even numbers
        if (k & 1) {
            for (a = 0; a <= k-1; a += 2) {
                b = k-a;
                if (a <= oddNumbers && b <= evenNumbers) {
                    result = max(result, pre(a, odd) + pre(b, even));
                }
            }
        }
        else {
            for (a = 0; a <= k; a += 2) {
                b = k-a;
                if (a <= oddNumbers && b <= evenNumbers) {
                    result = max(result, pre(a, odd) + pre(b, even));
                }
            }
        }
        return result;
    }
};