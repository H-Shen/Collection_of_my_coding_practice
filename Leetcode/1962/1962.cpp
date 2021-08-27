class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for (const auto &i : piles) {
            pq.push(i);
        }
        int temp;
        while (!pq.empty() && k > 0) {
            temp = pq.top();
            pq.pop();
            temp -= temp / 2;
            pq.push(temp);
            --k;
        }
        int sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};