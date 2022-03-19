using ll = long long;

class Solution {
public:
    // Greedy, binary search NOT needed!
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        ll sum = 0;
        for (auto&i : nums) {
            sum += i;
            pq.push(i);
        }
        double val;
        double sum_copy = sum;
        double temp;
        for (int i = 1;; ++i) {
            val = pq.top();
            pq.pop();
            temp = val/2.0;
            sum_copy -= temp;
            pq.push(temp);
            if (sum_copy * 2 <= sum) return i;
        }
        return -1;
    }
};