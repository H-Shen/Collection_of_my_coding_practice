class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        for (auto&i : amount) {
            if (i != 0) {
                pq.push(i);
            }
        }
        int counter = 0;
        int a, b;
        while (!pq.empty()) {
            if (pq.size() == 1) {
                counter += pq.top();
                pq.pop();
                continue;
            }
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            --a;
            --b;
            ++counter;
            if (a > 0) {
                pq.push(a);
            }
            if (b > 0) {
                pq.push(b);
            }
        }
        return counter;
    }
};