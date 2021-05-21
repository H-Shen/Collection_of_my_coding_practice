class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (const auto &i : stones) {
            pq.push(i);
        }
        int ans;
        while (true) {
            if (pq.empty()) {
                ans = 0;
                break;
            }
            else if (pq.size() == 1) {
                ans = pq.top();
                break;
            }
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if (x != y) {
                pq.push(y-x);
            }
        }
        return ans;
    }
};