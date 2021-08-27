class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        // https://www.luogu.com.cn/problem/P1090
        priority_queue<int, vector<int>, greater<> > pq;
        int n = (int)sticks.size();
        for (int i = 0; i < n; ++i) {
            pq.push(sticks[i]);
        }
        int cost = 0;
        int temp;
        while (pq.size() >= 2) {
            temp = pq.top();
            pq.pop();
            temp += pq.top();
            pq.pop();
            cost += temp;
            pq.push(temp);
        }
        return cost;
    }
};