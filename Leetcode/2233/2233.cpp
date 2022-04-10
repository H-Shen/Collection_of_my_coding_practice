using ll = long long;
constexpr ll MOD = 1e9+7;

class Solution {
public:
    // greedy
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> pq;
        for (auto&i : nums) pq.push(i);
        while (k--) {
            int temp = pq.top();
            pq.pop();
            pq.push(temp+1);
        }
        ll result = 1;
        while (!pq.empty()) {
            result = result * pq.top() % MOD;
            pq.pop();
        }
        return (int)(result % MOD);
    }
};