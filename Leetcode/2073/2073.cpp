class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = (int)tickets.size();
        deque<pair<int,int>> dq(n);
        for (int i = 0; i < n; ++i) {
            dq[i].first = tickets[i];
            dq[i].second = i;
        }
        int counter = 0;
        while (true) {
            pair<int,int> p = dq.front();
            dq.pop_front();
            --p.first;
            ++counter;
            if (p.first == 0) {
                if (p.second == k) {
                    return counter;
                }
            } else {
                dq.push_back(p);
            }
        }
    }
};